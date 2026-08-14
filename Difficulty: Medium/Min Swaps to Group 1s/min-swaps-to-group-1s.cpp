class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        int onecount=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1) onecount++;
        }
        if(onecount==0) return -1;
        int mini=INT_MAX;
        int one=0;
        for(int i=0;i<onecount;i++){
            if(arr[i]==1) one++;
        }
        mini=min(mini,onecount-one);
        for(int i=onecount;i<n;i++){
            if(arr[i-onecount]==1) one--;
            if(arr[i]==1) one++;
            mini=min(mini,onecount-one);
            
        }
        return mini;
        
    }
};