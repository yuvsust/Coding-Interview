class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)    continue;
            for(int j = i + 1; j < nums.size(); j++) {
                int last_side_range = nums[i] + nums[j];
				
				// Search for the maximum range of the third side
				// Lower bound will target to the first impossible value of the third side
				// So just add all indexes from 'j' to the 'iterator'
				// pointer of j = nums.begin() + j
                auto lower = lower_bound(nums.begin(), nums.end(), last_side_range);
                cnt += (lower - nums.begin() - j) - 1;
            }
        }
        return cnt;
    }
};