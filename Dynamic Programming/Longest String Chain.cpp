class Solution {
public:
    bool compare(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) return false;

        int f = 0, s = 0;
        while (f < s1.size()) {
            if (s < s2.size() && s1[f] == s2[s]) {
                f++;
                s++;
            } else {
                f++;
            }
        }
        return s == s2.size();
    }

    // Sort by length
    static bool cmp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (compare(words[i], words[prev]) && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
