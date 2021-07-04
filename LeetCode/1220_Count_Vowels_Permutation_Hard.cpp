class Solution {
public:
    int dp[20001][5];
    const int mod=1e9+7;
    int indexOf(char ch)
    {
        if(ch == 'a')   return 0;
        if(ch == 'e')   return 1;
        if(ch == 'i')   return 2;
        if(ch == 'o')   return 3;
        return 4;
    }
    int func(char ch, int n, int idx)
    {
        if(idx == n - 1)    return dp[idx][indexOf(ch)] = 1;
        if(dp[idx][indexOf(ch)] != -1)   return dp[idx][indexOf(ch)];
        long long  ans = 0;
        
        if(ch == 'a') {
            ans += func('e', n, idx + 1);
        }
        else if(ch == 'e') {
            ans += func('a', n, idx + 1);
            ans += func('i', n, idx + 1);
        }
        else if(ch == 'i') {
            ans += func('a', n, idx + 1);
            ans += func('e', n, idx + 1);
            ans += func('o', n, idx + 1);
            ans += func('u', n, idx + 1);
        }
        else if(ch == 'o') {
            ans += func('i', n, idx + 1);
            ans += func('u', n, idx + 1);
        }
        else if(ch == 'u') {
            ans += func('a', n, idx + 1);
        }

        //cout << st << endl;
        return dp[idx][indexOf(ch)] = ans % mod;
    }
    int countVowelPermutation(int n) {
        
        memset(dp, -1, sizeof dp);
        long long ans = 0; 
        ans += func('a', n, 0);
        ans %= mod;
        ans += func('e', n, 0);
        ans %= mod;
        ans += func('i', n, 0);
        ans %= mod;
        ans += func('o', n, 0);
        ans %= mod;
        ans += func('u', n, 0);
        ans %= mod;
        return ans;
    }
};