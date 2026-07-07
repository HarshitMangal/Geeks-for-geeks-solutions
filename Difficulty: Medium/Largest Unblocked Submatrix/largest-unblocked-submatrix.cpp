class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
          if (arr.empty())
            return n * m;

        vector<int> rows, cols;

        for (auto &it : arr) {
            rows.push_back(it[0]);
            cols.push_back(it[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRow = max(rows[0] - 1, n - rows.back());

        for (int i = 1; i < rows.size(); i++) {
            maxRow = max(maxRow, rows[i] - rows[i - 1] - 1);
        }

        int maxCol = max(cols[0] - 1, m - cols.back());

        for (int i = 1; i < cols.size(); i++) {
            maxCol = max(maxCol, cols[i] - cols[i - 1] - 1);
        }

        return maxRow * maxCol;
        
    }
};