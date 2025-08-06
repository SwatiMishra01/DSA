https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

class Solution {
private: 
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid,
             vector<pair<int, int>>& vec, int baseRow, int baseCol) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        
        // Record relative position
        vec.push_back({row - baseRow, col - baseCol});

        // 4 directions: up, left, down, right
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, vis, grid, vec, baseRow, baseCol);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st; // set to store unique island shapes

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec); // insert unique shape
                }
            }
        }

        return st.size();
    }
};
