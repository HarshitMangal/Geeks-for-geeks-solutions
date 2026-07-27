class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // Adjacency List -> {neighbor, weight}
        vector<pair<int,int>> adj[V];

        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});   // Undirected Graph
        }

        // Min Heap -> {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {

            auto front = pq.top();
            pq.pop();

            int d = front.first;
            int node = front.second;

            // Skip outdated entries
            if(d > dist[node])
                continue;

            for(auto &it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[adjNode]) {

                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if(dist[dest] == INT_MAX)
            return -1;

        return dist[dest];
        
    }
};