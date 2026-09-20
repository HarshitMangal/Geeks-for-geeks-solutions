class Solution {
public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();

        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        // Build right and down arrays
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;

                    if (j + 1 < n)
                        right[i][j] += right[i][j + 1];

                    if (i + 1 < n)
                        down[i][j] += down[i + 1][j];
                }
            }
        }

        // Try largest square first
        for (int size = n; size >= 1; size--) {

            for (int i = 0; i + size <= n; i++) {
                for (int j = 0; j + size <= n; j++) {

                    int bottom = i + size - 1;
                    int rightCol = j + size - 1;

                    // Top
                    if (right[i][j] < size)
                        continue;

                    // Left
                    if (down[i][j] < size)
                        continue;

                    // Bottom
                    if (right[bottom][j] < size)
                        continue;

                    // Right
                    if (down[i][rightCol] < size)
                        continue;

                    return size;
                }
            }
        }

        return 0;
    }
};