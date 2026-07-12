class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
       vector<vector<pair<int,int>>>adj(V);
       for(auto it:edges){
           int u=it[0];
           int v=it[1];
           int w=it[2];
           adj[u].push_back({v,w});
           adj[v].push_back({u,w});
       }
       //usiing min heap
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});
       vector<bool>visited(V,false);
       int sum=0;
       while(!pq.empty()){
           pair<int,int>front=pq.top();
           pq.pop();
           int w=front.first;
           int node=front.second;
           if(visited[node]==true) continue;
           visited[node]=true;
           sum+=w;
           for(auto it:adj[node]){
               int adjnode=it.first;
               int wt=it.second;
               if(!visited[adjnode])
               pq.push({wt,adjnode});
           }
       }

       return sum;
       
        
    }
};