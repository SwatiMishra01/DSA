https://leetcode.com/problems/01-matrix/description/
LEETCODE-542
  
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(mat[i][j]==0){
             q.push({{i,j},0});
             vis[i][j]=1;
          }
        }
      }
      while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int d=q.front().second;
        q.pop();
        dist[row][col]=d;

        //4 directions
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            if(nRow>=0 && nRow<n &&
               nCol>=0 && nCol<m &&
                vis[nRow][nCol]==0){
                    vis[nRow][nCol]=1;
                    q.push({{nRow,nCol},d+1});
                }
        }
      }
      return dist;

    }
};
T.C=O(N * M)
S.C=O(N * M)
