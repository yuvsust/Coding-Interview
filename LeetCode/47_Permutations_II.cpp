class Solution {
public:
    map <int, int> mp;
    void backtracking (vector<int>& nums, set < vector <int> >& ans, vector <int> v = {})
    {
        int sz = nums.size();
        int vsz = v.size();
        if(sz == vsz) {
            ans.insert(v);
            return;
        }
        if(vsz > sz)    return ;
        
        for(int i = 0; i < sz; i++) {
            if(mp[i+1])   continue;
            v.push_back(nums[i]);
            mp[i+1] = 1;
            backtracking(nums, ans, v);
            v.pop_back();
            mp[i+1] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set < vector <int> > ans_set;
        vector < vector <int> > ans;
        backtracking (nums, ans_set);
        for(auto it:ans_set) {
            ans.push_back(it);
        }
        return ans;
        
        
        /* Using Next Permutation */
        // sort(nums.begin(), nums.end());
        // do{
        //     ans.push_back(nums);
        // }   while(next_permutation(nums.begin(), nums.end()));
    }
};