class Solution {
    int findPar(vector<int> &parent, int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent, parent[node]);
    }

    void findUnion(vector<int> &parent, int u, int v) {
        u = findPar(parent, u);
        v = findPar(parent, v);

        if (u == v) return;
        if (u < v)
            parent[v] = u;
        else
            parent[u] = v;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++) parent[i] = i;

        // Union the equivalent characters
        for (int i = 0; i < s1.length(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            findUnion(parent, u, v);
        }

        // Build the result string
        string ans = "";
        for (char c : baseStr) {
            int rep = findPar(parent, c - 'a');
            ans += (char)(rep + 'a');
        }
        return ans;
    }
};
