class Solution {
public:
    int getMaxSumOfOneDimentionalArray(vector < int > v, int k)
    {
        set < int > st;
        int maxSum = -10000005;
        int cumSum = 0;
        st.insert(0);
        
        for(int i = 0; i < v.size(); i++) {
            cumSum += v[i];
            auto it = st.lower_bound(cumSum - k);
            if(it != st.end())
                maxSum = max(maxSum, cumSum - *it);
            st.insert(cumSum);
        }
        return maxSum;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        
        int l = 0, r = 0;
        int currentSum = 0;
        int maxSum = -10000005;
        
        while(l < col) {
            vector < int > v (row, 0);
            while(r < col) {
                for(int i = 0; i < row; i++) {
                    v[i] += matrix[i][r];
                }
                int maxCurrent = getMaxSumOfOneDimentionalArray(v, k);
                if(maxCurrent <= k && maxSum < maxCurrent) {
                    maxSum = maxCurrent;
                }
                r++;
            }
            l++;
            r = l;
        }
        
        return maxSum;
        
    }
};