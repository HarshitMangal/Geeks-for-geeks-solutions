class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
         int n = arr.size();

        vector<int> left(n), right(n);

        left[0] = arr[0];
        int ans = arr[0];

        // Kadane from left
        for (int i = 1; i < n; i++) {
            left[i] = max(arr[i], left[i - 1] + arr[i]);
            ans = max(ans, left[i]);
        }

        // Kadane from right
        right[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(arr[i], right[i + 1] + arr[i]);
        }

        // Delete one element
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, left[i - 1] + right[i + 1]);
        }

        return ans;
    }
};