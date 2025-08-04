https://leetcode.com/problems/number-of-provinces/description/
LEETCODE-547

  class Solution {
private:
    void dfs(int node, const vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);

        // Convert adjacency matrix to list
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(V, false);
        int cnt = 0;

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                ++cnt;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};

T.C= O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 
S.C=O(N) + O(N),Space for recursion stack space and visited array.
