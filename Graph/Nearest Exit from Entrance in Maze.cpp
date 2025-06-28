class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        queue<pair<int, int>> q;

        int ex = entrance[0], ey = entrance[1];
        q.push({ex, ey});
        vis[ex][ey] = 1;
        int cnt = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && !(x == ex && y == ey)) 
                    return cnt;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && maze[nx][ny] == '.') {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            cnt++;
        }

        return -1;
    }
};
