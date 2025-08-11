https://leetcode.com/problems/pacific-atlantic-water-flow/
LEETCODE-417

--------------------------
  RECURSION-TLE
----------------------------
  
class Solution {
   
    //directions-> up,right,down,left (clockwise)
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    private:
    bool reachPacific(int row,int col,vector<vector<int>>& heights,vector<vector<bool>> &visitedP){
         int n=heights.size();
         int m=heights[0].size();


        if (row < 0 || col < 0) return true; // touched Pacific border
        if (visitedP[row][col]) return false;

        visitedP[row][col] = true;

        for (auto &d : dirs) {
            int nr = row + d[0];
            int nc = col + d[1];
            if (nr >= 0 && nr < n &&
                 nc >= 0 && nc < m &&
                heights[nr][nc] <= heights[row][col]) {
                if (reachPacific(nr, nc, heights, visitedP)) return true;
            } else if (nr < 0 || nc < 0) {
                // directly reached Pacific
                return true;
            }
        }
        return false;
    }
    bool reachAtlantic(int row, int col,vector<vector<int>>& heights,vector<vector<bool>> &visitedA){
         int n=heights.size();
        int m=heights[0].size();

        if (row >= n || col >= m) return true; // touched Atlantic border
        if (visitedA[row][col]) return false;

        visitedA[row][col] = true;

        for (auto &d : dirs) {
            int nr = row + d[0];
            int nc = col + d[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                heights[nr][nc] <= heights[row][col]) {
                if (reachAtlantic(nr, nc, heights, visitedA)) return true;
            } else if (nr >= n || nc >= m) {
                // directly reached Atlantic
                return true;
            }
        }
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>result;
        int n=heights.size();
        int m=heights[0].size();


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<bool>> visitedP(n, vector<bool>(m, false));
                vector<vector<bool>> visitedA(n, vector<bool>(m, false));
                if(reachPacific(i,j,heights,visitedP)==true && reachAtlantic(i,j,heights,visitedA)==true){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
T.C=O((n·m)²)
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------
    USING DFS
  ----------------
  class Solution {
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    int n, m;

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for (auto &d : dirs) {
            int nr = row + d[0];
            int nc = col + d[1];
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[row][col]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific: top row + left column
        for (int i = 0; i < n; i++) dfs(i, 0, heights, pacific);
        for (int j = 0; j < m; j++) dfs(0, j, heights, pacific);

        // Atlantic: bottom row + right column
        for (int i = 0; i < n; i++) dfs(i, m - 1, heights, atlantic);
        for (int j = 0; j < m; j++) dfs(n - 1, j, heights, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
T.C=O(n·m)
S.C=O(n·m)
