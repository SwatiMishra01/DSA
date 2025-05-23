CONDITIONS:
--> each row= 1Q
--> each column= 1Q
--> no 2 Q attack each other


------------------------------------------------------------------------------------------------------------------
  
  
 #include <bits/stdc++.h> 
void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board, int n){
  vector<int>temp;
  for(int i=0; i<n; i++){
    for(int j=0;j<n;j++){
      temp.push_back(board[i][j]);
    }
  }
  ans.push_back(temp);
}






bool isSafe(int row, int col, vector<vector<int>> &board, int n){
  // 3 conditions
  int x=row;
  int y=col;
  //check same row
  while(y>=0){
    if(board[x][y]==1)
      return false;
    y--;
  }

  //upper left diagonal check
  x=row;
  y=col;
  while(x>=0 && y>=0){
    if(board[x][y]==1)
      return false;
    y--;
    x--;
  }
  //lower left diagonal check
   x=row;
  y=col;
  while(x<n && y>=0){
    if(board[x][y]==1)
      return false;
    y--;
    x++;
  }
  return true;
}









void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board, int n){
  //base case
  if(col==n){
    addSolution(ans,board, n);
    return;
  }
  //solve 1 case rest leave it on RECURSION
  for(int row=0; row<n; row++){
    if(isSafe(row,col,board,n)){
      //if safe
      board[row][col]=1;
      solve(col+1,ans,board,n);  // recursion
      board[row][col]=0;         //backtrack
    }
  }
}






vector<vector<int>> nQueens(int n)                                  //MAIN STATEMENT FROM QUES
{
	vector<vector<int>> board(n, vector<int>(n,0));
  vector<vector<int>> ans;

  solve(0,ans,board,n);
    return ans;
	
}
