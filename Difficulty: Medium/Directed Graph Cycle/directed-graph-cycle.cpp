class Solution {
  public:
   bool solve(vector<vector<int>>&adj,vector<bool>&inrec,vector<bool>&visited,int u){
       visited[u]=true;
       inrec[u]=true;
       for(auto it:adj[u]){
           if(inrec[it]==true)return true;
           if(!visited[it]){
               if(solve(adj,inrec,visited,it)) return true;
           }
       }
       inrec[u]=false;
       return false;
   }
    bool isCyclic(int V, vector<vector<int>> &edges) {
         vector<vector<int>>adj(V);
       for(auto it:edges){
           int u=it[0];
           int v=it[1];
           adj[u].push_back(v);
           
       }
       vector<bool>visited(V,false);
       vector<bool>inrecursion(V,false);
       for(int i=0;i<V;i++){
           if(!visited[i]&&!inrecursion[i]){
              if(solve(adj,inrecursion,visited,i)) return true;
           }
       }
       return false;
    }
    
};