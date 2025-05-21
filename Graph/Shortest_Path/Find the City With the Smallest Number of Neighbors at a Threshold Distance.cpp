class Solution {
public:
    void Shortest(vector<vector<int>> &mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1)
                    mat[i][j] = 1e9;
                if (i == j)
                    mat[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        Shortest(dist);

        int minReachable = n + 1;
        int city = -1;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }
            
            if (count <= minReachable) {
                minReachable = count;
                city = i;
            }
        }

        return city;
    }
};
