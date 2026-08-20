class Solution {
  public:
    int transform(string &A, string &B) {
      if(A.length()!=B.length()) return -1;
      int n=A.length();
      unordered_map<char,int>mp1;
      unordered_map<char,int>mp2;
      for(auto it:A) mp1[it]++;
      for(auto it:B) mp2[it]++;
      if(mp1!=mp2) return -1;
      int ans=0;
      int i=n-1;
      int j=n-1;
      while(i>=0&&j>=0){
          while(i>=0&&A[i]!=B[j]){
              ans++;
              i--;
          }
          i--;
          j--;
      }
       return ans;
        
    }
};
