class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        step1: reverse matrix up to down
        step2: swap symetric element. For example: {(0,2)<=>(2,0) , (1,3)<=>(3,1)}
        */
        
        // REVERSE MATRIX UP TO DOWN
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row / 2; i++) {
            for(int j = 0; j < col; j++) {
                swap(matrix[i][j], matrix[row-i-1][j]);
            }
        }
        
        // SWAP SYMMETRIC ELEMENTS
        for(int i = 0; i < row; i++) {
            for(int j = i; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};
