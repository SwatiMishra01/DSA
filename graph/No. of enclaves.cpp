https://leetcode.com/problems/number-of-enclaves/
LEETCODE-1020

class Solution {
    private:
    void dfs(int row, int col,vector<vector<int>>&vis, vector<vector<int>>& grid,vector<vector<int>>&copy ){
        int n=grid.size();
        int m=grid[0].size();

        vis[row][col]=1;
        copy[row][col]=0;

        //4 directions
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};

        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];


            if(nRow>=0 && nRow<n &&
               nCol>=0 && nCol<m &&
               !vis[nRow][nCol] && grid[nRow][nCol]==1){
                  dfs(nRow, nCol, vis, grid, copy);
               }
        }
            }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>copy=grid;
        //1st and last row 1's
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j]==1) dfs(0,j,vis,grid,copy);
            if(!vis[n-1][j] &&grid[n-1][j]==1) dfs(n-1,j,vis,grid,copy);
        }

        //1st and last col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]==1) dfs(i,0,vis,grid,copy);
            if(!vis[i][m-1] && grid[i][m-1]==1) dfs(i,m-1,vis,grid,copy);
        }



        //now traversing all through copy and counting ones
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(copy[i][j]==1) ans++;
            }
        }
        return ans;

    }
};
