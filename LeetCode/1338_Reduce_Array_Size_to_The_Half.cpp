class Solution {
public:
    static bool cmp(pair < int, int > &a, pair < int, int > &b)
    {
        return a.second > b.second;
    }
    int minSetSize(vector<int>& arr) {
        int len = arr.size();
        map < int, int > mp;
        for(auto it:arr) {
            mp[it]++;
        }
        vector < pair < int, int > > v;
        for(auto it:mp)     v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        
        int cnt = 0;
        int sets = 0;
        while(cnt < len/2) {
            cnt += v[sets].second;
            sets++;
        }
        
        return sets;
    }
};