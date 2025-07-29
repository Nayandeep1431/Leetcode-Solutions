class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;
        if (n == 0) return ans;

        unordered_map<int, int> x, y, pd, sd;
        set<pair<int, int>> st;
        for (const auto& lamp : lamps) {
            int i = lamp[0], j = lamp[1];
            if (st.count({i, j})) continue;
            x[i]++;
            y[j]++;
            pd[i + j]++;
            sd[i - j]++;
            st.insert({i, j});
        }

        for (const auto& query : queries) {
            int i = query[0], j = query[1];
            if (x[i] > 0 || y[j] > 0  || pd[i + j] > 0 || sd[i - j] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && st.count({ni, nj})) {
                        st.erase({ni, nj});
                        x[ni]--;
                        y[nj]--;
                        pd[ni + nj]--;
                        sd[ni - nj]--;
                    }
                }
            }
        }
        return ans;
    }
};
