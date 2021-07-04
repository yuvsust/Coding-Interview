class Solution {
public:
    vector<int> grayCode(int n) {
        vector < string > v = {"0", "1"};
        //if(n == 1)  return v;
        for(int i = 2; i <= n; i++) {
            vector < string > tmp;
            for(auto it:v) {
                tmp.push_back("0" + it);
            }
            for(int i = v.size() - 1; i >= 0; i--) {
                tmp.push_back("1" + v[i]);
            }
            v = tmp;
        }
        vector < int > ans;
        for(auto it:v)  ans.push_back(stoi(it, nullptr, 2));
        return ans;
    }
};