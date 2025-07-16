class Solution {
public:
    int N;
    vector<int> count;
    long long root_result = 0;

    int dfs(unordered_map<int, list<int>> &adj, int node, int par, int depth) {
        int total = 1;
        root_result += depth;

        for (auto it : adj[node]) {
            if (it != par) {
                total += dfs(adj, it, node, depth + 1);
            }
        }

        count[node] = total;
        return total;
    }

    void DFS(unordered_map<int, list<int>> &adj, int node, int par, vector<int> &res) {
        for (auto it : adj[node]) {
            if (it == par) continue;

            res[it] = res[node] - count[it] + (N - count[it]);
            DFS(adj, it, node, res);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        unordered_map<int, list<int>> adj;
        N = n;
        count.resize(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        root_result = 0;
        dfs(adj, 0, -1, 0);

        vector<int> res(n, 0);
        res[0] = root_result;
        DFS(adj, 0, -1, res);
        return res;
    }
};
