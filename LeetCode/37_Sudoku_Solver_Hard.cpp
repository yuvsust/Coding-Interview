class Solution {
public:
    bool backtrack(int row, int col, vector<vector<char>>& board)
    {
        if(row >= 9)    return true;
        if(board[row][col] != '.')  {
            if(col == 8)    col = 0, row++;
            else    col++;
            return backtrack(row, col, board);
        }
        bool is_valid = false;
        int val = 0;
        for(char i = '1'; i <= '9'; i++) {
            bool inRowBefore = false;
            bool inColBefore = false;
            bool inBoxBefore = false;
            for (int j = 0; j < 9; j++) {
                if(board[row][j] == i)    {
                    inRowBefore = true;
                    break;
                }
                if(board[j][col] == i){    
                    inColBefore = true;
                    break;
                }
            }
            if (inRowBefore || inColBefore)     continue;
            for (int j = (row/3)*3; j < (row/3)*3 + 3; j++) {
                for (int k = (col/3)*3; k < (col/3)*3 + 3; k++) {
                    if(board[j][k] == i) {
                        inBoxBefore = true;
                        break;
                    }
                }
            }
            if(inBoxBefore) continue;
            board[row][col] = i;
            
            int tmp_row = row, tmp_col = col;
            if(tmp_col == 8)    tmp_col = 0, tmp_row++;
            else    tmp_col++;
            is_valid = backtrack(tmp_row, tmp_col, board);
            if(is_valid)    return true;
            board[row][col] = '.';
        }
        
        return is_valid;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool receive = backtrack(0, 0, board);
    }
};