class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>>ans;
        int n=arr.size();
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            while(size--){
                 int idx=q.front();
                 q.pop();
                 temp.push_back(arr[idx]);
                 if(2*idx+1<n){
                     q.push(2*idx+1);
                 }
                 if(2*idx+2<n){
                     q.push(2*idx+2);
                 }
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
        
    }
};
