class Solution {
public:
    bool bfs(unordered_map<int, list<int>> &mpp, vector<int> &color, int node) {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (auto it : mpp[top]) {
                if (color[it] == -1) {
                    color[it] = 1 - color[top];
                    q.push(it);
                } else if (color[it] == color[top]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        unordered_map<int, list<int>> mpp;
        for (auto &edge : dislikes) {
            mpp[edge[0]].push_back(edge[1]);
            mpp[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1); 
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!bfs(mpp, color, i)) return false;
            }
        }
        return true;
    }
};
