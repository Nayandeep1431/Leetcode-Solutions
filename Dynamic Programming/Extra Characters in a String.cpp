class Solution {
public:
    int solve(int ind, const string &s, unordered_set<string> &st, vector<int> &dp) {
        if (ind == s.length())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int ans = INT_MAX;
        string curr = "";
        for (int i = ind; i < s.length(); i++) {
            curr += s[i];
            int extra = st.count(curr) ? 0 : curr.length();
            ans = min(ans, extra + solve(i + 1, s, st, dp));
        }
        return dp[ind] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(s.length(), -1);
        return solve(0, s, st, dp);
    }
};
