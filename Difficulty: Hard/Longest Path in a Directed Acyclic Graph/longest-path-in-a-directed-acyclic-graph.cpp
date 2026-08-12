class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
           //sabse phle directed acyclic garph
          vector<vector<pair<int,int>>>adj(V);
          vector<int>indegree(V,0);
          for(auto edge:edges){
              int  u=edge[0];
              int v=edge[1];
              int w=edge[2];
              adj[u].push_back({v,w});
              indegree[v]++;
          }
          //using topological sorting karunge is quetion me
          queue<int>q;
          for(int i=0;i<V;i++){
              if(indegree[i]==0) q.push(i);
          }
           vector<int>topoorder;
           while(!q.empty()){
               int u=q.front();
               q.pop();
               topoorder.push_back(u);
               for(auto it:adj[u]){
                  int v=it.first;
                  int w=it.second;
                  indegree[v]--;
                  if(indegree[v]==0) q.push(v);
               }
           }
           //distance array for lobngest path
           vector<int>dist(V,INT_MIN);
           dist[src]=0;
           for(int u:topoorder){
               if(dist[u]!=INT_MIN){
                   for(auto it:adj[u]){
                       int v=it.first;
                       int w=it.second;
                       dist[v]=max(dist[v],dist[u]+w);
                   }
               }
           }
           return dist;
        
    }
};