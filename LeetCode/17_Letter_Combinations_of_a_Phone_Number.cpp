class Solution {
public:
    map < char, string > mp;
    
    vector<string> letterCombinations(string digits) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        int sz = digits.size();
        vector<string> v;
        if(sz == 0)     return v;
        
        v.push_back("");
        for (auto d:digits) {
            vector <string> temp;
            for(auto c:mp[d]) {
                for(auto s:v) {
                    string comb = s + c;
                    temp.push_back(comb);
                }
            }
            v = temp;
        }
        return v;
    }
};