https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
-----------------------------
  USING TOPOSORT
-----------------------------
class Solution {
private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<pair<int,int>> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                dfs(v, vis, st, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // adjacency list
        vector<pair<int,int>> adj[V];
        for(int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // topological sort
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // distance calculation
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // unreachable nodes
        for(int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
