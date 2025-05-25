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

--------------------------------------------------------------------------------------------------------------------
LEETCODE m string k form m answer maaangra that thats y a little changes
--------------------------------------------------------------------------------------------------------------------
	LEETCODE: # https://leetcode.com/problems/n-queens/description/


	//isSafe function
bool isSafe(int row, int col, vector<vector<int>>&board, int n){
    int x = row;
    int y = col;

    // check upper-left diagonal
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check left side in the same row
    y = col;
    while (y >= 0) {
        if (board[row][y] == 1)
            return false;
        y--;
    }

    // check lower-left diagonal
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}









//addSolution function

void addSolution(vector<vector<int>>&ans,vector<vector<int>>&board, int n){
    vector<int>temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}








//solve function
void solve(int col, vector<vector<int>>&ans,vector<vector<int>>&board, int n){
    //base case
    if(col==n){
        addSolution(ans,board,n);
        return;
    }
    //solving 1 case and rest RECURSION will handle
    for(int row=0; row<n; row ++){
        if (isSafe(row,col,board,n)){
        //is safe
        board[row][col]=1;
        solve(col+1, ans, board, n); //recursion
        board[row][col]=0; //backtrack
        }
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        solve(0,ans,board,n);
        vector<vector<string>> finalAns;
        for (auto temp : ans) {
            vector<string> output;
            for (int i = 0; i < n; i++) {
                string row = "";
                for (int j = 0; j < n; j++) {
                    if (temp[i * n + j] == 1)
                        row += 'Q';
                    else
                        row += '.';
                }
                output.push_back(row);
            }
            finalAns.push_back(output);
        }
        return finalAns;
    }
};
