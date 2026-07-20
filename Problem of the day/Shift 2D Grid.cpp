class Solution {
public:
    typedef vector<vector<int>> v;
    int n, m;

    void solve(v &ans, v &grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == n - 1 && j == m - 1)
                    ans[0][0] = grid[i][j];

                else if (j == m - 1)
                    ans[i + 1][0] = grid[i][j];

                else
                    ans[i][j + 1] = grid[i][j];
            }
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < k; i++) {
            vector<vector<int>> ans(n, vector<int>(m));
            solve(ans, grid);
            grid = ans;
        }

        return grid;
    }
};
