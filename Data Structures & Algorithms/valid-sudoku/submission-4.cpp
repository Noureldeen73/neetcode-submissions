class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check Rows first
        for (int r = 0; r < 9; r++){
            int count[10] = {0};
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.') continue;
                int num = board[r][c] - '0';

                if(count[num] != 0) return false;

                count[num]++;
            }
        }
        // Check Columns second
        for (int c = 0; c < 9; c++){
             int count[10] = {0};
            for(int r = 0; r < 9; r++){
                if(board[r][c] == '.') continue;
                int num = board[r][c] - '0';

                if(count[num] != 0) return false;

                count[num]++;
            }
        }

        // Check groups
        for (int k = 0; k < 9; k++){
            int start_r = k / 3;
            int start_c = k % 3;
            int count[10] = {0};
            for(int r = start_r * 3; r < start_r * 3 + 3; r++){
                for(int c = start_c * 3; c < start_c * 3 + 3; c++){
                if(board[r][c] == '.') continue;
                int num = board[r][c] - '0';

                if(count[num] != 0) return false;

                count[num]++;
                }
            }
        }
        return true;
    }
};
