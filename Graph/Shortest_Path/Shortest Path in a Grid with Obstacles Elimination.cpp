class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;

    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k+1, false)));
        
        queue<vector<int>> q;
        q.push({0, 0, k});
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto curr = q.front();
                q.pop();
                int x = curr[0], y = curr[1], rem = curr[2];
                
                if (x == n-1 && y == m-1)
                    return steps;
                
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (grid[nx][ny] == 0 && !visited[nx][ny][rem]) {
                            visited[nx][ny][rem] = true;
                            q.push({nx, ny, rem});
                        }
                        else if (grid[nx][ny] == 1 && rem > 0 && !visited[nx][ny][rem-1]) {
                            visited[nx][ny][rem-1] = true;
                            q.push({nx, ny, rem-1});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
