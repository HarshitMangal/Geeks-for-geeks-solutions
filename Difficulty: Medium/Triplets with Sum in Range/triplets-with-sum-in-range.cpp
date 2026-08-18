class Solution {
  public:
   int solve(vector<int>&arr,int n,int x){
      sort(arr.begin(),arr.end());
       int count=0;
       for(int i=0;i<n-2;i++){
           int j=i+1;
           int k=n-1;
           while(j<k){
               if(arr[i]+arr[j]+arr[k]<=x){
                   count+=k-j;
                   j++;
               }
               else k--;
           }
       }
       return count;
   }
  int countTriplets(vector<int> &arr, int L, int R) {
      int n=arr.size();
        return solve(arr,n,R)-solve(arr,n,L-1);
        
    }
};