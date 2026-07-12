class Solution {
  public:
    bool solve(vector<vector<int>>&adj,int u,int parent,vector<bool>&visited){
        visited[u]=true;
        for(auto it:adj[u]){
            if(it==parent) continue;
            if(visited[it]==true)  return true;
            if(!visited[it]){
                if(solve(adj,it,u,visited)==true) return true;
              }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adj(V);
       for(auto it:edges){
           int u=it[0];
           int v=it[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       vector<bool>visited(V,false);
         for(int i=0;i<V;i++){
             if(!visited[i]){
                 if(solve(adj,i,-1,visited)) return true;
             }
         }
         return false;
       
        
    }
};