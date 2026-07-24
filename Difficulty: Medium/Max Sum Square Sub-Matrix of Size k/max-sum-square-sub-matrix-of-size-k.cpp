class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {

        int n = mat.size();

        vector<vector<int>> prefix(n, vector<int>(n, 0));

        // Build 2D Prefix Sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int up = (i > 0) ? prefix[i - 1][j] : 0;
                int left = (j > 0) ? prefix[i][j - 1] : 0;
                int diag = (i > 0 && j > 0) ? prefix[i - 1][j - 1] : 0;

                prefix[i][j] = mat[i][j] + up + left - diag;
            }
        }

        int ans = INT_MIN;

        // Check every k x k submatrix
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                int row = i + k - 1;
                int col = j + k - 1;

                int sum = prefix[row][col];

                if (i > 0)
                    sum -= prefix[i - 1][col];

                if (j > 0)
                    sum -= prefix[row][j - 1];

                if (i > 0 && j > 0)
                    sum += prefix[i - 1][j - 1];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};