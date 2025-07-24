https://leetcode.com/problems/n-queens/description/
LEETCODE-51
--------------------------
      BRUTE FORCE
--------------------------

class Solution {
public:

    // Function to check if it's safe to place a queen at (row, col)
    bool isSafe1(int row, int col, vector<string> board, int n) {
        int duprow = row;
        int dupcol = col;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // Reset row and col to original values
        row = duprow;
        col = dupcol;

        // Check left side of the current row
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // Reset row and col again
        row = duprow;
        col = dupcol;

        // Check lower-left diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true; // Safe to place the queen
    }

    // Recursive function to solve the problem
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        // Base case: all queens are placed
        if (col == n) {
            ans.push_back(board); // Store the current valid board configuration
            return;
        }

        // Try placing queen in every row for the current column
        for (int row = 0; row < n; row++) {
            if (isSafe1(row, col, board, n)) {
                board[row][col] = 'Q';         // Place queen
                solve(col + 1, board, ans, n); // Recur for next column
                board[row][col] = '.';         // Backtrack: remove queen
            }
        }
    }

    // Main function to return all valid N-Queens board configurations
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;         // To store the final answers
        vector<string> board(n,string(n,'.'));            // Board of size n x n
                                                     // Initial empty row with all '.'


        solve(0, board, ans, n); // Start solving from column 0
        return ans;
    }
};
T.C=(N! * N)
S.C=O(N^2)
