
class Solution {
  public:
 string findpattern(string &s){
     int n=s.length();
     string temp="";
   for(int i=1;i<n;i++){
       int diff=s[i]-s[i-1];
       if(diff<0) diff+=26;
       temp+=(to_string(diff)+"_");
   }
     return temp;
 }
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
          vector<vector<string>>ans;
          unordered_map<string ,vector<string>>mp;
          int n=arr.size();
          for(auto it:arr){
              string pattern= findpattern(it);
              mp[pattern].push_back(it);
          }
          for(auto it:mp){
              ans.push_back(it.second);
          }
          return ans;
        
    }
};