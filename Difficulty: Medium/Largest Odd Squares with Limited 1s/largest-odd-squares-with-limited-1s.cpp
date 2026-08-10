class Solution {
  public:
     int getsum(int r1, int c1, int r2, int c2,
               vector<vector<int>>& prefix) {

        int sum = prefix[r2][c2];

        if(r1 > 0)
            sum -= prefix[r1-1][c2];

        if(c1 > 0)
            sum -= prefix[r2][c1-1];

        if(r1 > 0 && c1 > 0)
            sum += prefix[r1-1][c1-1];

        return sum;
    }
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
     
       int n = mat.size();
        int m = mat[0].size();

        // 2D Prefix Sum
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                prefix[i][j] = mat[i][j];

                if(i > 0)
                    prefix[i][j] += prefix[i-1][j];

                if(j > 0)
                    prefix[i][j] += prefix[i][j-1];

                if(i > 0 && j > 0)
                    prefix[i][j] -= prefix[i-1][j-1];
            }
        }

        vector<int> ans;

        // Har query
        for(auto &q : queries) {

            int i = q[0];
            int j = q[1];

            int best = -1;

            // Radius
            for(int r = 0; ; r++) {

                int top = i - r;
                int bottom = i + r;
                int left = j - r;
                int right = j + r;

                // Matrix ke bahar chala gaya
                if(top < 0 || bottom >= n ||
                   left < 0 || right >= m) {
                    break;
                }

                int sum = getsum(top, left, bottom, right, prefix);

                if(sum <= k) {
                    best = 2 * r + 1;
                }
                else {
                    // Binary matrix hai, expand karne par
                    // ones kam nahi honge.
                    break;
                }
            }

            ans.push_back(best);
        }

        return ans;
       
        
    }
};