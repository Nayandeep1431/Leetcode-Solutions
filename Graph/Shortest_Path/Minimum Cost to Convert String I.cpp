class Solution {
    typedef long long ll;

    void floydWarshall(vector<vector<ll>> &adj) {
        for (int i = 0; i < 26; i++)
            adj[i][i] = 0;

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adj[i][k] < 1e9 && adj[k][j] < 1e9)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if (source.size() != target.size()) return -1;

        vector<vector<ll>> adj(26, vector<ll>(26, 1e9));
        int n = original.size();

        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u][v] = min(adj[u][v], (ll)cost[i]);
        }

        floydWarshall(adj);

        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (u == v) continue;
            if (adj[u][v] >= 1e9) return -1;

            ans += adj[u][v];
        }

        return ans;
    }
};
