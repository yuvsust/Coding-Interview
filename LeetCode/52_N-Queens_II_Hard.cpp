class Solution {
public:
    int backtrack(int n, int row, vector < string > board)
    {
        if(row == n)    return 1;
        
        bool fl;
        int ways = 0;
        for(int col = 0; col < n; col++) {
            fl = true;
            for(int i = 1; i <= row; i++) {
                if(board[row - i][col] == 'Q')  {fl = false; break;}
                if(col + i < n && board[row - i][col + i] == 'Q')   {fl = false; break;}
                if(col - i >= 0 && board[row - i][col - i] == 'Q')  {fl = false; break;}
            }
            if(fl) {
                board[row][col] = 'Q';
                ways += backtrack(n, row + 1, board);
                board[row][col] = '.';
            }
        }
        return ways;
    }
    int totalNQueens(int n) {
        vector < string > v;
        string board(n, '.');
        for(int i = 0; i < n; i++)  v.push_back(board);
        return backtrack(n, 0, v);
    }
};