class Solution {
public:
    int dp[105];
    int func(int idx, string data)
    {
        if(data[0] == '0')	return 0;
        if(idx >= data.size() || data == "")	return 1;
        if(dp[idx] != -1)   return dp[idx];
        if(data[idx] >= '3')	return dp[idx] = func(idx+1, data);
        if(data[idx] == '2') {
            if(idx == data.size()-1 || data[idx+1] > '6')	return dp[idx] = func(idx+1, data);
            else  {
                return dp[idx] = func(idx+1, data) + func(idx+2, data);
            }
        }
        if(data[idx] == '1') {
            if(idx == data.size()-1)	return dp[idx] = func(idx+1, data);
            else  {
                return dp[idx] = func(idx+1, data) + func(idx+2, data);
            }
        }
        return dp[idx] = 0;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return func(0, s);
    }
};