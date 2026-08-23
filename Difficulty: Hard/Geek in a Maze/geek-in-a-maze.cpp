


class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // If the starting cell is an obstacle, 0 cells can be visited
        if (mat[r][c] == '#') return 0;

        // min_u[i][j] stores the minimum up moves needed to reach (i, j)
        vector<vector<int>> min_u(n, vector<int>(m, 1e9));
        deque<pair<int, int>> dq;

        min_u[r][c] = 0;
        dq.push_back({r, c});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            int cur_u = min_u[x][y];
            int cur_d = cur_u + x - r; // d_used is uniquely determined by u_used and current row

            // 1. Move Up (Cost in up moves: 1 -> push to back)
            int nx = x - 1, ny = y;
            if (nx >= 0 && mat[nx][ny] != '#') {
                if (cur_u + 1 <= u && cur_d <= d) {
                    if (cur_u + 1 < min_u[nx][ny]) {
                        min_u[nx][ny] = cur_u + 1;
                        dq.push_back({nx, ny});
                    }
                }
            }

            // 2. Move Down (Cost in up moves: 0 -> push to front)
            nx = x + 1, ny = y;
            if (nx < n && mat[nx][ny] != '#') {
                if (cur_u <= u && cur_d + 1 <= d) {
                    if (cur_u < min_u[nx][ny]) {
                        min_u[nx][ny] = cur_u;
                        dq.push_front({nx, ny});
                    }
                }
            }

            // 3. Move Left (Cost in up moves: 0 -> push to front)
            nx = x, ny = y - 1;
            if (ny >= 0 && mat[nx][ny] != '#') {
                if (cur_u <= u && cur_d <= d) {
                    if (cur_u < min_u[nx][ny]) {
                        min_u[nx][ny] = cur_u;
                        dq.push_front({nx, ny});
                    }
                }
            }

            // 4. Move Right (Cost in up moves: 0 -> push to front)
            nx = x, ny = y + 1;
            if (ny < m && mat[nx][ny] != '#') {
                if (cur_u <= u && cur_d <= d) {
                    if (cur_u < min_u[nx][ny]) {
                        min_u[nx][ny] = cur_u;
                        dq.push_front({nx, ny});
                    }
                }
            }
        }

        // Count all reachable distinct empty cells
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (min_u[i][j] != 1e9) {
                    count++;
                }
            }
        }

        return count;
    }
};

