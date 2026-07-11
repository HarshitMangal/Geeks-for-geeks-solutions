class Solution {
  public:
    const int mod=1e9+7;
    int maxAmount(vector<int>& arr, int k) {
      int n=arr.size();
      priority_queue<int>pq;
      for(int i=0;i<n;i++){
          pq.push(arr[i]);
      }
      int ans=0;
      while(k!=0){
          int x=pq.top();
           pq.pop();
           if(x<=0){
               return ans;
           }
           ans=(ans+x)%mod;
           x--;
           pq.push(x);
           k--;
          
      }
      return ans%mod;
         
        
    }
};