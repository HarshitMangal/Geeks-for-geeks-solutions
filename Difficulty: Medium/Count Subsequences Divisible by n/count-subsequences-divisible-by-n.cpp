class Solution {
  public:

    int MOD = 1e9 + 7;

    int Count(string &s, int &size, int &divisor, int idx, int rem, vector<vector<int>> &dp)
    {
        if(idx == size)
        return rem == 0;

        if(dp[idx][rem] != -1)
        return dp[idx][rem];

        int num = s[idx] - '0';

        int newRem = (rem * 10 + num) % divisor;

        int take = Count(s,size,divisor,idx+1,newRem,dp);

        int skip = Count(s,size,divisor,idx+1,rem,dp);

        return dp[idx][rem] = (skip + take) % MOD;
    }

    int countSubsequences(string& s, int n) {
        // code here

        int m = s.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return Count(s,m,n,0,0,dp) - 1;
    }
};
