https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
LEETCODE-1091

  -------------------
  UDING DIJKSTRA'S
  -------------------
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<pair<int,int>> dirs = {
            {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}
        };
        
        // min-heap {distance, {row, col}}
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({1, {0,0}});
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        
        while (!pq.empty()) {
            auto [d, rc] = pq.top(); pq.pop();
            int r = rc.first, c = rc.second;
            
            if (r == n-1 && c == n-1) return d;
            
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0) {
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        pq.push({d+1, {nr,nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};
⚡ Complexity

Time: O(n² log n)
At most n² cells, each can be pushed/popped from heap → O(log(n²)) = O(log n²) = O(2 log n) → simplified to O(log n).

Space: O(n²)
dist + pq storage.

  ---------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------
          USING BFS
  ------------------------------
  class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<pair<int,int>> dirs = {
            {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}
        };

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; // mark visited, also stores distance

        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            int d = grid[r][c];

            if (r == n-1 && c == n-1) return d;

            for (auto [dr,dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0) {
                    grid[nr][nc] = d + 1; // store distance directly
                    q.push({nr,nc});
                }
            }
        }

        return -1;
    }
};
T.C=O(n²)
S.C=O(n²)
