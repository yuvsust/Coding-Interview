class Solution {
public:
    void backtrack(vector < vector < string > >& ans, vector < string > board, int n, int row)
    {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        bool fl = true;
        for(int col = 0; col < n; col++) {
            fl = true;
            for(int i = 1; i <= row; i++) {
                if(board[row - i][col] == 'Q')   {fl = false; break;}
                if(col + i < n && board[row - i][col + i] == 'Q')   {fl = false; break;}
                if(col - i >= 0 && board[row - i][col - i] == 'Q')  {fl = false; break;}
            }
            if(fl) {
                board[row][col] = 'Q';
                backtrack(ans, board, n, row + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector < vector < string > > ans;
        vector < string > board;
        string row (n, '.');
        for(int i = 0; i < n; i++) {
            board.push_back(row);
        }
        backtrack(ans, board, n, 0);
        return ans;
    }
};