class Solution {
public:
    typedef long long ll;

    ll shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.length();
        ll cost = 0;  // Use long long to avoid overflow

        for (int i = 0; i < n; i++) {
            int s1 = s[i] - 'a';
            int t1 = t[i] - 'a';

            int f = (t1 - s1 + 26) % 26;  // Forward distance
            int b = (s1 - t1 + 26) % 26;  // Backward distance

            ll fwdcost = 0, bckcost = 0;

            for (int j = 0; j < f; j++) {
                fwdcost += nextCost[(s1 + j) % 26];
            }

            for (int j = 0; j < b; j++) {
                bckcost += previousCost[(s1 - j + 26) % 26];
            }

            cost += min(fwdcost, bckcost);
        }

        return cost;
    }
};
