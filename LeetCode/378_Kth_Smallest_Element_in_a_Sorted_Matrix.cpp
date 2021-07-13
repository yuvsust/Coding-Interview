class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /*        Using Binary Search   O(n (log(n))^2 )       */
         int n = matrix.size();
         int lo = matrix[0][0], hi = matrix[n-1][n-1];
         int mid;
      
         while(lo < hi) {
             mid = (lo + hi) / 2;
             int cnt = 0;
             for(int i = 0; i < n; i++) {
                 cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
             }
             if(cnt < k)     lo = mid + 1;
             else    hi = mid;
         }
         return lo;
        /*        Using Binary Search Ends       */
        
        
        /*        Using Linear Data Structure     O(n^2 + nlog(n) )      */
		
//        int n = matrix.size();
//        vector < int > v;
//        for(int i = 0; i < n; i++)  for(int j = 0; j < n; j++)  v.push_back(matrix[i][j]);
//        sort(v.begin(), v.end());
//        return v[k-1];
        
		/*        Using Linear Data Structure Ends       */
    }
};