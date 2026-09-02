class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n=arr.size();
      vector<vector<int>>dp(n,vector<int>(2,0));

       dp[0][0] = 0;
       dp[0][1] = 0;

       for(int i=1;i<n;i++){
           dp[i][0] = max(abs(arr[i] - arr[i-1]) + dp[i-1][0], abs(arr[i] - 1) + dp[i-1][1]);
           dp[i][1] = max(abs(1 - arr[i-1]) + dp[i-1][0], abs(1 - 1) + dp[i-1][1]);
       }

       return max(dp[n-1][0],dp[n-1][1]);
        
    }
};