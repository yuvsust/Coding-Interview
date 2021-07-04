class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int idx, set < vector <int> >& ans_set, vector < int > v = {})
    {
        if(target == 0) {
            sort(v.begin(), v.end());
            ans_set.insert(v);
            return;
        }
        int sz = candidates.size();
        
        for(int i = idx; i < sz; i++) {
            if(target - candidates[i] < 0)  return;
            v.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, ans_set, v);
            while(i + 1 < sz && candidates[i] == candidates[i + 1])     i++;
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set < vector <int> > ans_set;
        vector < vector <int> > ans;
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, ans_set);
        for(auto it:ans_set) {
            ans.push_back(it);
        }
        return ans;
    }
};