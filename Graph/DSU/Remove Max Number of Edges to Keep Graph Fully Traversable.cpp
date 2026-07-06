class Solution {
public:
    int parent(int node, vector<int>& par) {
        if (par[node] == node)
            return node;
        return par[node] = parent(par[node], par);
    }

    void unionRank(int u, int v, vector<int>& par, vector<int>& rank) {
        u = parent(u, par);
        v = parent(v, par);

        if (u == v) return;

        if (rank[u] < rank[v])
            par[u] = v;
        else if (rank[u] > rank[v])
            par[v] = u;
        else {
            par[v] = u;
            rank[u]++;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b) {
                 return a[0] > b[0];
             });

        vector<int> par1(n), par2(n), rank1(n, 0), rank2(n, 0);

        for (int i = 0; i < n; i++) {
            par1[i] = i;
            par2[i] = i;
        }

        int cnt = 0;

        for (auto &it : edges) {

            int type = it[0];
            int u = it[1] - 1;
            int v = it[2] - 1;

            if (type == 1) {

                if (parent(u, par1) == parent(v, par1))
                    cnt++;
                else
                    unionRank(u, v, par1, rank1);

            }
            else if (type == 2) {

                if (parent(u, par2) == parent(v, par2))
                    cnt++;
                else
                    unionRank(u, v, par2, rank2);

            }
            else {

                bool merged = false;

                if (parent(u, par1) != parent(v, par1)) {
                    unionRank(u, v, par1, rank1);
                    merged = true;
                }

                if (parent(u, par2) != parent(v, par2)) {
                    unionRank(u, v, par2, rank2);
                    merged = true;
                }

                if (!merged)
                    cnt++;
            }
        }

        int root = parent(0, par1);
        for (int i = 1; i < n; i++)
            if (parent(i, par1) != root)
                return -1;

        root = parent(0, par2);
        for (int i = 1; i < n; i++)
            if (parent(i, par2) != root)
                return -1;

        return cnt;
    }
};
