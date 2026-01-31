class Solution {
private:
    bool isSafe(vector<string>& board, int col, int row, int n) {
        int r = row, c = col;

        // upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // left side
        c = col;
        while (c >= 0) {
            if (board[row][c] == 'Q')
                return false;
            c--;
        }

        // lower-left diagonal
        r = row;
        c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        return true;
    }

private:
    void solve(vector<vector<string>>& ans, vector<string>& board, int n,
               int col) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(board, col, row, n)) {
                board[row][col] = 'Q';
                solve(ans, board, n, col + 1); // move to next column
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        solve(ans, board, n, 0); // start from column 0
        return ans;
    }
};
