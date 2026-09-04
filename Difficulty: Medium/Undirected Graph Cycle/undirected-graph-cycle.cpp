class Solution {
  public:
     bool cancycle(vector<vector<int>>&adj,int u,int parent,vector<bool>&visited){
        visited[u]=true;
         for(auto v:adj[u]){
             if(v==parent) continue;
            if(visited[v]==true) return true;
            if(!visited[v]){
            if(cancycle(adj,v,u,visited)) return true;
            }

         }
         return false;
     }
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n=edges.size();
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
            if(cancycle(adj,i,-1,visited)) return true;
           }
       }
       return false;
        
    }
};