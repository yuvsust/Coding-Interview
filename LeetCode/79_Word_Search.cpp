class Solution {
public:
    
    
    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int idx) {
        int row = board.size();
        int col = board[0].size();
        if(idx == word.size())  return true;
        bool fl = false;
        char tmp = board[r][c];
        board[r][c] = '*';
        int dRow[4] = { -1, 0, 1, 0 };
        int dCol[4] = { 0, 1, 0, -1 };
        for(int i = 0; i < 4; i++) {
            int x = r + dRow[i];
            int y = c + dCol[i];
            if(x >= 0 && x < row && y >= 0 && y < col && board[x][y] == word[idx]) {
                fl = backtrack(board, word, x, y, idx + 1);
                if(fl) return fl;
            }
        }
        board[r][c] = tmp;
        return fl;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        bool ans = false;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0]) {
                    ans = backtrack(board, word, i, j, 1);
                    if(ans) return ans;
                }
            }
        }
        return ans;
    }
};