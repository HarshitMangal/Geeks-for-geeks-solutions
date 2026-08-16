class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {

        int N = n * n;

        // moves[i] = destination if there is a snake/ladder at i
        vector<int> moves(N, -1);

        // Ladders
        for(int i = 0; i < lad.size(); i += 2) {
            int u = lad[i];
            int v = lad[i + 1];

            moves[u - 1] = v - 1;
        }

        // Snakes
        for(int i = 0; i < sn.size(); i += 2) {
            int u = sn[i];
            int v = sn[i + 1];

            moves[u - 1] = v - 1;
        }

        vector<bool> visited(N, false);

        // {position, number of throws}
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0] = true;

        while(!q.empty()) {

            auto [pos, dist] = q.front();
            q.pop();

            // Reached n*n
            if(pos == N - 1)
                return dist;

            // Try dice values 1 to 6
            for(int dice = 1; dice <= 6; dice++) {

                int next = pos + dice;

                // Cannot go beyond n*n
                if(next >= N)
                    break;

                if(visited[next])
                    continue;

                visited[next] = true;

                // Snake or ladder
                if(moves[next] != -1)
                    next = moves[next];

                q.push({next, dist + 1});
            }
        }

        return -1;
    }
};