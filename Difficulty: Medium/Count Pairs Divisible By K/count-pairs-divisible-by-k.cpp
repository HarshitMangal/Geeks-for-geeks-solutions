class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        int n=arr.size();
            long long count=0;
        unordered_map<int,int >fre;
        for(int i=0;i<n;i++){
            int rem=(arr[i]%k+k)%k;
            int need=(k-rem)%k;
            if(fre.find(need)!=fre.end()){
                count+=fre[need];
            }
            fre[rem]++;
            
        }
        return count;
        
    }
};