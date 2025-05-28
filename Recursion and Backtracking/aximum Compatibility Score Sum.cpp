class Solution {
    int cal(vector<vector<int>> &s, vector<vector<int>> &m, int i, int j) {
        int cnt = 0;
        for (int k = 0; k < m[0].size(); k++) {
            if (s[i][k] == m[j][k])
                cnt++;
        }
        return cnt;
    }

    int solve(vector<vector<int>> &s, vector<vector<int>> &m, vector<int> &vis, int ind, int n) {
        if (ind == n)
            return 0;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                ans = max(ans, cal(s, m, ind, i) + solve(s, m, vis, ind + 1, n));
                vis[i] = 0;
            }
        }
        return ans;
    }

public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors) {
        int n = students.size();
        vector<int> vis(n, 0);
        return solve(students, mentors, vis, 0, n);
    }
};
