class Solution {
public:
    int dp[1005][1005];
    int mx = 0;
    int func(vector<int>& nums1, vector<int>& nums2, int i, int j)
    {
        if(i >= nums1.size())   return 0;
        if(j >= nums2.size())   return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        int cnt = 0;
        if(nums1[i] == nums2[j])    cnt = 1 + func(nums1, nums2, i+1, j+1);
        func(nums1, nums2, i, j+1), func(nums1, nums2, i+1, j);
        mx = max(mx, cnt);
        return dp[i][j] = cnt;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset (dp, -1, sizeof dp);
        func(nums1, nums2, 0, 0);
        return mx;
    }
};