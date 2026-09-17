class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        deque<int>q;
        vector<int>dist(n+1,INT_MAX);
        q.push_front(src);
        dist[src]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop_front();
            for(auto it:adj[u]){
                int v=it.first;
                int cost=it.second;
                if(dist[u]+cost<dist[v]){
                    dist[v]=dist[u]+cost;
                    if(cost==0){
                        q.push_front(v);
                    }
                    if(cost==1){
                        q.push_back(v);
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
        
    }
};