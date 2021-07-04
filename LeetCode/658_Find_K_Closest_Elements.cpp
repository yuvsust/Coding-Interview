class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int mn_index = -1;
        int mn = 10005;
        vector < pair <int, int> > diff;
        for(int i = 0; i < arr.size(); i++) {
            diff.push_back({abs(arr[i] - x), i});
        }
        sort(diff.begin(), diff.end());
        vector <int> ans;
        for(auto it:diff)   {
            ans.push_back(arr[it.second]);
            k--;
            if(k == 0)  break;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};