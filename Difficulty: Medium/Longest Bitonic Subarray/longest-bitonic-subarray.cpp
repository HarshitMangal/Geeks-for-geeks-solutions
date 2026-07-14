class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        vector<int> inc(n, 1), dec(n, 1);

        // Allow non-strictly increasing
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }

        // Allow non-strictly decreasing
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }

        int maxlen = 1;
        for (int i = 0; i < n; i++) {
            maxlen = max(maxlen, inc[i] + dec[i] - 1);
        }

        return maxlen;
    }
};