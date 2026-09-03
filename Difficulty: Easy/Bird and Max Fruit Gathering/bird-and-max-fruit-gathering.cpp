class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
         int ans=0, n=arr.size();
      
      int temp=0;
      for(int i=0;i<m;i++){
          temp += arr[i];
      }
      
      ans = max(ans, temp);
      
      for(int i=1;i<n;i++){
          temp -= arr[i-1];
          temp += arr[(i+m-1)%n];
          ans = max(ans, temp);
      }
      
      return ans;
        
    }
};