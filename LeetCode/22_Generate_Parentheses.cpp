class Solution {
public:
    void backtrack(int n, int opening, int closing, string st, vector < string > &v)
    {
        if(st.size() == n + n) {
            v.push_back(st);
            return;
        }
        if(opening < n) {
            backtrack(n, opening + 1, closing, st + "(", v);
        }
        if(closing < opening) {
            backtrack(n, opening, closing + 1, st + ")", v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector < string > v;
        backtrack(n, 0, 0, "", v);
        return v;
    }
};