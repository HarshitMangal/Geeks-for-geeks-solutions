class Solution {
  public:
    void dfs1(vector<vector<int>>&adj,stack<int>&st,vector<bool>&visited,int u){
          visited[u]=true;
          for(auto it:adj[u]){
              if(!visited[it]){
                  dfs1(adj,st,visited,it);
              }
          }
          st.push(u);
    }
    void dfs2(vector<vector<int>>&adj,int u,vector<bool>&visited){
        visited[u]=true;
        for(auto it:adj[u]){
            if(!visited[it]){
                dfs2(adj,it,visited);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
      vector<vector<int>>adj(V);
      for(auto it:edges){
          int u=it[0];
          int v=it[1];
          adj[u].push_back(v);
      }
         stack<int>st;
        vector<bool>visited(V,false);
      for(int i=0;i<V;i++){
          if(!visited[i]){
              dfs1(adj,st,visited,i);
          }
      }
        
        fill(visited.begin(),visited.end(),false);
        //ab iske bad revese karenge
        vector<vector<int>>revadj(V);
        for(int i=0;i<V;i++){
            for(auto v:adj[i]){
                revadj[v].push_back(i);
            }
        }
        int count=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                count++;
                dfs2(revadj,node,visited);
            }
        }
        return count;
        
        
    }
};