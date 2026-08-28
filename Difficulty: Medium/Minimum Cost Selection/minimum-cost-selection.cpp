class Solution {
	public:
	int solve(int row, int col, vector<vector<int>> & dp,
	const int& n,
	const vector<vector<int>> & mat) {
		if (row >= n || col >= 3)
			return INT_MAX;

		if (row == n - 1)
			return mat[row][col];

		if (dp[row][col] != INT_MAX)
			return dp[row][col];

		int ans = INT_MAX;
		for (int c = 0; c<3; c++) {
			if (c == col)
				continue;
			ans = min(ans, solve(row + 1, c, dp, n, mat));
		}

		return dp[row][col] = mat[row][col] + ans;
	}
	int minCost(vector<vector<int>> & mat) {
		// code here
		int n = mat.size();
		vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
		int ans = INT_MAX;
		for (int i = 0; i<3; i++) {
			ans = min(ans, solve(0, i, dp, n, mat));
		}
		return ans;
	}
};