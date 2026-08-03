class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
     int n = arr.size();

        // maxEnding[i] = maximum subarray sum ending at index i
        vector<int> maxEnding(n);

        maxEnding[0] = arr[0];

        for (int i = 1; i < n; i++) {
            maxEnding[i] = max(arr[i], arr[i] + maxEnding[i - 1]);
        }

        // First window of size k
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int ans = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {

            windowSum += arr[i];
            windowSum -= arr[i - k];

            // Case 1: Take only current window
            ans = max(ans, windowSum);

            // Case 2: Extend current window with best left subarray
            ans = max(ans, windowSum + maxEnding[i - k]);
        }

        return ans;
    }
};