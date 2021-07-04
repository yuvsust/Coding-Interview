class Solution {
public:
    set < vector <int> > ans_set;
    void backtrack(vector<int>& candidates, int target, vector < int > v = {})
    {
        if(target == 0)     {
            sort(v.begin(), v.end());
            ans_set.insert(v);
            return;
        }
        if(target < 0)      return ;
        
        int sz = candidates.size();
        for(int i = 0; i < sz; i++) {
            if(target - candidates[i] < 0)   return;
            v.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], v);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target);
        vector < vector<int> > ans;
        for(auto it:ans_set) {
            ans.push_back(it);
        }
        return ans;
    }
};