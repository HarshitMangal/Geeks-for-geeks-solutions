class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
       vector<int>ans(n,1);
       stack<int>st;
       //using monotonic stack 
       for(int i=0;i<n;i++){
           while(!st.empty()&&arr[i]>=arr[st.top()]){
               ans[i]+=ans[st.top()];
               st.pop();
               }
              st.push(i);
       }
        return ans;
       
        
    }
};