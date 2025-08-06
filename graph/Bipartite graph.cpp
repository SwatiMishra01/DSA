https://leetcode.com/problems/is-graph-bipartite/description/
LEETCODE- 785

  --------------------------------
  APPROACH 1-> USING BFS
  --------------------------------
class Solution {
public:
    bool check(int start , int color[] ,vector<vector<int>>& graph){
        queue<int>q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }else if(color[it] == color[node]){
                    return false;
                }
            }
        }
    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i =0 ; i<n ; i++){
            color[i] = -1;
        }

        for(int i =0 ; i<n ; i++){
            if(color[i] == -1){
                if(check(i , color , graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};

--------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------
   APPROACH 2-> USING DFS
  -----------------------------
  class Solution {
private:
    bool dfs(int node, int color[], vector<vector<int>>& graph) {
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                color[it] = !color[node]; // assign opposite color
                if (!dfs(it, color, graph)) return false;
            } else if (color[it] == color[node]) {
                return false; // same color on both ends = not bipartite
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for (int i = 0; i < n; i++) color[i] = -1;

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i, color, graph)) return false;
            }
        }
        return true;
    }
};
