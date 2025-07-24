https://leetcode.com/problems/sudoku-solver/description/
LEETCODE-37


  --------------------------
      BACTRACKING
----------------------------
  class Solution {
public:
    // Function to check if placing 'c' at board[row][col] is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check column
            if (board[i][col] == c) return false;

            // Check row
            if (board[row][i] == c) return false;

            // Check 3x3 subgrid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true; // Valid move
    }

    // Recursive backtracking function to solve the Sudoku board
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // If the current cell is empty
                if (board[i][j] == '.') {
                    // Try placing digits from '1' to '9'
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place the digit

                            // Recur to solve the rest of the board
                            if (solveSudoku(board))
                                return true;
                            else
                                board[i][j] = '.'; // Backtrack
                        }
                    }
                    // If no digit can be placed, return false
                    return false;
                }
            }
        }
        return true; // All cells filled successfully
    }
};
