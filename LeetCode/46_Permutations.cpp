class Solution {
public:
    map < int, int > mp;
    void backtrack(vector<int>& nums, vector < vector <int> >& ans, vector <int> v = {})
    {
        int sz = nums.size();
        int idx = v.size();
        if(idx ==  sz)  {
            ans.push_back(v);
            return;
        }
        if(idx > sz)    return;
        
        for(int i = 0; i < sz; i++) {
            if(mp[nums[i]])     continue;
            v.push_back(nums[i]);
            mp[nums[i]] = 1;
            backtrack(nums, ans, v);
            v.pop_back();
            mp[nums[i]] = 0;
        }        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector < vector <int> > ans;
        // vector < int > v;
        // backtrack(nums, ans);
        // return ans;
        
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        }   while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};