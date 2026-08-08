class Solution {
  public:
     vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void union_set(int x, int y) {
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
    int minEdgesReq(int n, vector<vector<int>>& edge) {
        int e = edge.size();
        if (e < n - 1) return -1; // Not enough edges to connect all nodes

        parent.resize(n);  // ❗ Use n, not V
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for (auto &vec : edge) {
            if (find(vec[0]) != find(vec[1])) {
                union_set(vec[0], vec[1]);
                components--;
            }
        }

        return components - 1;
        
    }
};