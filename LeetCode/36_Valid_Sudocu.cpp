class Solution {
public:
    bool inRow(vector<vector<char>> board, int r, int c)
    {
        char num = board[r][c];
        for(int j = 0; j < 9; j++) {
            if(j == c)  continue;
            if(board[r][j] == num)  return true;
        }
        return false;
    }
    bool inCol(vector<vector<char>> board, int r, int c)
    {
        char num = board[r][c];
        for(int i = 0; i < 9; i++) {
            if(i == r)  continue;
            if(board[i][c] == num)  return true;
        }
        return false;
    }
    bool inBox(vector<vector<char>> board, int r, int c)
    {
        char num = board[r][c];
        for(int i = (r/3)*3; i < (r/3)*3+3; i++) {
            for(int j = (c/3)*3; j < (c/3)*3+3; j++) {
                if(i == r && j == c)    continue;
                if(board[i][j] == num)  return true;
            }
        }
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')  continue;
                if(inRow(board, i, j) || inCol(board, i, j) || inBox(board, i, j))
                    return false;
            }
        }
        return true;
    }
};