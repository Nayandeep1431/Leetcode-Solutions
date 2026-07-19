class Solution {
public:
    typedef long long ll;

    string num;
    int K;
    static const int mod = 1e9 + 7;

    ll dp[101][11][2][2];

    ll solve(int pos, int prev, bool tight, bool started) {
        if (pos == num.size())
            return started;

        if (dp[pos][prev][tight][started] != -1)
            return dp[pos][prev][tight][started];

        int limit = tight ? (num[pos] - '0') : 9;

        ll ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            if (!started) {
                if (d == 0) {
                    ans = (ans + solve(pos + 1, 10, newTight, false)) % mod;
                } else {
                    ans = (ans + solve(pos + 1, d, newTight, true)) % mod;
                }
            } else {
                if (abs(prev - d) == K) {
                    ans = (ans + solve(pos + 1, d, newTight, true)) % mod;
                }
            }
        }

        return dp[pos][prev][tight][started] = ans;
    }

    int count(string s, int k) {
        num = s;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 10, true, false);
    }

    string subtractOne(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }

        if (i >= 0)
            s[i]--;

        int pos = 0;
        while (pos + 1 < s.size() && s[pos] == '0')
            pos++;

        s = s.substr(pos);

        if (s == "")
            s = "0";

        return s;
    }

    int countSteppingNumbers(string low, string high) {
        string lowMinusOne = subtractOne(low);

        int highCnt = count(high, 1);
        int lowCnt = count(lowMinusOne, 1);

        return (highCnt - lowCnt + mod) % mod;
    }
};
