class Solution {
public:
    int dp[2505][2505];
    int func(vector<int>& nums, int i, int prev)
    {
        if(i >= nums.size())    return 0;
        if(dp[i][prev+1] != -1)     return dp[i][prev+1];
        int taken = 0, not_taken;
        not_taken = func(nums, i+1, prev);
        if(prev == -1 || nums[i] > nums[prev]) {
            taken = 1 + func(nums, i+1, i);
        }
        return dp[i][prev+1] = max(taken, not_taken);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return func(nums, 0, -1);
    }
};