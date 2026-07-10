class Solution {
  public:
      int maxlen;

    void solve(vector<vector<int>>& mat, vector<vector<bool>>& visited,
               int x, int y, int a, int b, int len) {
        int n = mat.size();
        int m = mat[0].size();

        if (x == a && y == b) {
            maxlen = max(maxlen, len);
            return;
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                !visited[nx][ny] && mat[nx][ny] == 1) {
                visited[nx][ny] = true;
                solve(mat, visited, nx, ny, a, b, len + 1);
                visited[nx][ny] = false; // backtrack
            }
        }
    }

    int longestPath(vector<vector<int>>& mat, int x, int y, int xd, int yd) {
         int n = mat.size();
        int m = mat[0].size();

        if (mat[x][y] == 0 || mat[xd][yd] == 0) return -1; // blocked

        maxlen = -1;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        visited[x][y] = true; // source mark visited
        solve(mat, visited, x, y, xd, yd, 0);

        return maxlen;
        
    }
};