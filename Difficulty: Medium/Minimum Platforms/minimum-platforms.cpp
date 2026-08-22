class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
       sort(arr.begin(),arr.end());
       sort(dep.begin(),dep.end());
       int n=arr.size();
       int i=0;
       int j=0;
       int ans=0;
       int maxi=0;
       while(i<n&&j<n){
          if(arr[i]<=dep[j]){
              ans++;
               maxi=max(maxi,ans);
              i++;
          }
          else{
               ans--;
               j++;
          }
       }
       return maxi;
        
    }
};
