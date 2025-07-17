class Solution {
public:
    typedef long long ll;

    int solve(int node, vector<vector<int>>& adj, vector<int>& size) {
        int ans = 1;
        for (auto it : adj[node]) {
            ans += solve(it, adj, size);
        }
        return size[node] = ans;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> adj(n);
        int root = -1;

        for (int i = 0; i < n; i++) {
            if (parents[i] == -1)
                root = i;
            else
                adj[parents[i]].push_back(i);
        }

        vector<int> size(n);
        solve(root, adj, size);

        ll maxi = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            ll pro = 1;
            int rest = n - size[i];
            if (rest > 0)
                pro *= rest;

            for (auto child : adj[i]) {
                pro *= size[child];
            }

            if (pro > maxi) {
                maxi = pro;
                cnt = 1;
            } else if (pro == maxi) {
                cnt++;
            }
        }
        return cnt;
    }
};
