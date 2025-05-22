# https://www.naukri.com/code360/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

  ----------------------------------------------------------------------------------------------------------------------------
  📌 Step-by-step Logic:
--> Empty Cell Dhoondo:
      -Poore grid mein ek empty cell (jisme value 0 ya '.') hai usko search karo.

--> 1 se 9 Tak Try Karo:
        -Us empty cell mein 1 se 9 tak ke numbers try karo.
        -Har number ke liye vo 3 conditions check karo:

--> Valid Hai Toh Recursively Solve Karo:
               - Agar valid hai, toh us number ko wahan daal kar recursive call karo agla empty cell solve karne ke liye.

--> Agar Recursion Fail Kare Toh Backtrack Karo:
                   -Agar kisi number ke baad koi solution nahi milta, toh usko hata do (undo karo) aur next number try karo.

--> Agar Poora Grid Fill Ho Gaya Toh Solution Mil Gaya:
                   - Jab saare cells fill ho jaate hain bina kisi conflict ke, toh solution mil gaya.

----------------------------------------------------------------------------------------------------------------------------------

  PSEUDOCODE:
Function SolveSudoku(board):
    For each row from 0 to 8:
        For each column from 0 to 8:
            If board[row][col] is empty:
                For num from 1 to 9:
                    If isValid(board, row, col, num):
                        board[row][col] = num
                        
                        If SolveSudoku(board) returns true:
                            Return true
                        
                        board[row][col] = empty  // Backtrack
                End For

                Return false  // No valid number found for this cell
            End If
        End For
    End For

    Return true  // All cells are filled correctly
End Function
-------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h> 
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
}
-------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h> 


bool isSafe(int row, int col,vector<vector<int>>& board, int val ){
    for(int i=0; i<board.size(); i++){

         //checking all three conditions

        //row check
        if(board[row][i]==val)
        return false;
        //col check
        if(board[i][col]==val)
        return false;
        //3*3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        return false;
    }
   return true;
}






bool solve(vector<vector<int>>& board){
    int n=board[0].size();
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            //check is cell empty
            if(board[row][col]==0){
                for(int val=1; val<=9; val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        //recursive call
                        bool aageSolutionPossible=solve(board);
                        if(aageSolutionPossible)
                        return true;
                        else
                        {
                            //backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}




void solveSudoku(vector<vector<int>>& sudoku)    //MAIN STATEMENT QUES
{
	solve(sudoku);
}
