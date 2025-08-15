class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> st(forbidden.begin(), forbidden.end());
        vector<vector<int>> vis(2, vector<int>(6001, 0));
        queue<pair<int, bool>> q;
        vis[0][0] = 1;
        vis[1][0] = 1;

        q.push({0, false});
        int ans = 0;
        int max_pos = max(x, *max_element(forbidden.begin(), forbidden.end())) + a + b;

        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto [node, flag] = q.front();
                q.pop();

                if (node == x)
                    return ans;

                int fwd = node + a;
                int bck = node - b;

                if (fwd <= max_pos && vis[0][fwd] == 0 && !st.count(fwd)) {
                    q.push({fwd, false});
                    vis[0][fwd] = 1;
                }    

                if (bck >= 0 && vis[1][bck] == 0 && !flag && !st.count(bck)) {
                    q.push({bck, true});
                    vis[1][bck] = 1;
                }
            }
            ans++;
        }
        return -1;
    }
};
