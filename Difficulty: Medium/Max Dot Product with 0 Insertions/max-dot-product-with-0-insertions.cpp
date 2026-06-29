class Solution {
  public:
        vector<vector<int>> dp;

    int solve(vector<int> &a, vector<int> &b, int i, int j) {

        int n = a.size();
        int m = b.size();

        // b ke saare elements use ho gaye
        if (j == m)
            return 0;

        // a khatam ho gaya lekin b abhi bhi bacha hai
        if (i == n)
            return -1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        // a[i] ke saamne 0 insert kar do
        int skip = solve(a, b, i + 1, j);

        // a[i] ko b[j] ke saath pair karo
        int take = a[i] * b[j] + solve(a, b, i + 1, j + 1);

        return dp[i][j] = max(skip, take);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
          int n=a.size();
          int m=b.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));

        return solve(a, b, 0, 0);
        
    }
};
