https://leetcode.com/problems/find-eventual-safe-states/description/
LEETCODE-802

  class Solution {
private:
    // detect cycles and mark safe nodes
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, 
             vector<int>& pathVis, vector<int>& check) {

        vis[node] = 1;         
        pathVis[node] = 1;     
        check[node] = 0;    

        // Traverse all adjacent nodes
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, graph, vis, pathVis, check)) {
                    // If a cycle is detected in the path, current node is unsafe
                    check[node] = 0;
                    return true;
                }
            }
            // If adjacent node is visited and also in current path -> cycle found
            else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), check(n, 0);
        vector<int> safeNodes;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        // Collect all safe nodes (i.e., nodes not part of any cycle)
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
