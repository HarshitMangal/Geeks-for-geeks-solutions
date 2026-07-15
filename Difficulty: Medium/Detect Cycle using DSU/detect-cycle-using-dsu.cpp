class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unionset(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        // Union by rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                if (u < v) { // To ensure each edge is considered only once
                    int parent_u = find(u);
                    int parent_v = find(v);

                    if (parent_u == parent_v) return true;

                    unionset(u, v);
                }
            }
        }

        return false; // No cycle found
    }
};