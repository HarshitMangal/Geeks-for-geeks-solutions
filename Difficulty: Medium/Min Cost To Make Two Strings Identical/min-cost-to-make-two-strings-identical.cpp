class Solution {
  public:
     int solve(vector<vector<int>>& ans, int n, int m, string& s1, string& s2) {
            if (n == 0 || m == 0) return 0;
            if (ans[n][m] != -1) return ans[n][m];

            if (s1[n - 1] == s2[m - 1]) {
                return ans[n][m] = 1 + solve(ans, n - 1, m - 1, s1, s2);
            } else {
                return ans[n][m] = max(solve(ans, n - 1, m, s1, s2), solve(ans, n, m - 1, s1, s2));
            }
        }

    int findMinCost(string &s1, string &s2, int costX, int costY) {
         int n = s1.length();
          int m = s2.length();

          vector<vector<int>> ans(n + 1, vector<int>(m + 1, -1));
          int lcsLen = solve(ans, n, m, s1, s2);

          int totalCost = (n - lcsLen) * costX + (m - lcsLen) * costY;
          return totalCost;
        
    }
};