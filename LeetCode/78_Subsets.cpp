class Solution {
public:
    void backtrack(vector<int>& nums, vector < vector <int> >& ans, int n, int idx, vector < int > v = {})
    {
        if(v.size() == n)   {
            ans.push_back(v);
            return;
        }
        int sz = nums.size();
        for(int i = idx; i < sz; i++) {
            v.push_back(nums[i]);
            backtrack(nums, ans, n, i + 1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector < vector <int> > ans;
        sort (nums.begin(), nums.end());
        int sz = nums.size();
        ans.push_back({});
        for(int i = 1; i <= sz; i++) {
            backtrack(nums, ans, i, 0);
        }
        return ans;
    }
};