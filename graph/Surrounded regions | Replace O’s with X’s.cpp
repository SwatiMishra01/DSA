https://leetcode.com/problems/surrounded-regions/description/
LEETCODE- 130

  class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>&vis,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        //check fro all directions
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};

        for(int i=0 ;i<4; i ++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            if(nRow>=0 && nRow<n &&
               nCol>=-0 && nCol<m &&
               board[nRow][nCol]=='O' && !vis[nRow][nCol]){
                dfs(nRow,nCol,vis,board);
               }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        //traverse 1st row, 1st col, last row, last col and check if there are 0's

        //1st row & last row-> traverse through every column
        for(int j=0; j<m; j++){
         if(!vis[0][j] && board[0][j]=='O'){ //1st row
            dfs(0,j,vis,board);
         }
         if(!vis[n-1][j] && board[n-1][j]=='O'){ //last row
           dfs(n-1,j,vis,board);
         }
        }

        //last row & last col->traverese each row
       for(int i=0; i<n; i++){
        if(!vis[i][0] && board[i][0]=='O') dfs(i,0,vis,board);
        if(!vis[i][m-1] && board[i][m-1]=='O') dfs(i,m-1,vis,board);
       }


       for( int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
        }
       }
    }
};
T.C=O(N * M)
S.C=O(N * M)
