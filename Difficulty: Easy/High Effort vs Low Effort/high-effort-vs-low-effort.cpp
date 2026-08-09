class Solution {
  public:
         int solve(vector<int>& h, vector<int>& l, int i, int prev,
              vector<vector<int>>& dp) {
        
        int n = h.size();

        if (i == n)
            return 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        // 1. No task today
        int noTask = solve(h, l, i + 1, 1, dp);

        // 2. Low effort today
        int low = l[i] + solve(h, l, i + 1, 0, dp);

        // 3. High effort today
        int high = 0;

        if (prev == 1) {
            high = h[i] + solve(h, l, i + 1, 0, dp);
        }

        return dp[i][prev] = max({noTask, low, high});
    }

    int maxTask(vector<int>& h, vector<int>& l) {
         int n = h.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        // prev = 1 means previous day had no task
        return solve(h, l, 0, 1, dp);
        
    }
};