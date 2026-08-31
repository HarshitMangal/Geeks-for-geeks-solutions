class Solution {
  public:
    int minCost(int n, int i, int d, int c) {

        vector<long long> dp(n + 2, 0);

        dp[1] = i;

        for (int x = 2; x <= n; x++) {

            // Insert one character
            dp[x] = dp[x - 1] + i;

            if (x % 2 == 0) {
                // x/2 ko double karke x
                dp[x] = min(dp[x], dp[x / 2] + c);
            } 
            else {
                // (x+1)/2 ko double karke x+1,
                // fir ek character delete
                dp[x] = min(dp[x], 
                            dp[(x + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};