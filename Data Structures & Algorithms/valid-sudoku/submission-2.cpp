class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int boxrow = 0, boxcol = 0;
        for (int i = 0; i < board.size(); i++) {
            vector<bool> r(10, false);
            for (int col = 0; col < 9; col++) {
                if (isdigit(board[i][col])) {
                    if (r[board[i][col]]) {
                        return false;
                    }
                    r[board[i][col]] = true;
                }
            }
            vector<bool> c(10, false);
            for (int row = 0; row < 9; row++) {
                if (isdigit(board[row][i])) {
                    if (c[board[row][i]]) {
                        return false;
                    }
                    c[board[row][i]] = true;
                }
            }
            vector<bool> b(10, false);
            int startr = (i / 3) * 3, startc = (i % 3) * 3;
            for (int row = startr; row < startr + 3; row++) {
                for (int col = startc; col < startc + 3; col++) {
                    if (isdigit(board[row][col])) {
                        if (b[board[row][col]]) {
                            return false;
                        }
                        b[board[row][col]] = true;
                    }
                }
            }
        }
        return true;
    }
};