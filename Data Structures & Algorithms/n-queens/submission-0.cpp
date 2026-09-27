class Solution {
public:
    vector<vector<string>> ans;
    
    // check if placing a queen is safe
    bool isSafe(vector<string> &board, int row, int col, int n) {
        // check upper column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    // dfs to place queens row by row
    void dfs(vector<string> &board, int row, int n) {
        if (row == n) {                  // all queens placed
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';   // place queen
                dfs(board, row + 1, n);  // go to next row
                board[row][col] = '.';   // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n);
        return ans;
    }
};
