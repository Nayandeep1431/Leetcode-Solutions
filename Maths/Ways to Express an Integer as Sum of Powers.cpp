class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7 ;
    int findWays(vector<ll> &arr, int k) {
        int n = arr.size();
        vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        if (arr[0] <= k)
            dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int tar = 1; tar <= k; tar++) {
                ll notTaken = dp[ind - 1][tar];
                ll taken = 0;
                if (arr[ind] <= tar)
                    taken = dp[ind - 1][tar - arr[ind]];
                dp[ind][tar] = (notTaken % mod + taken % mod) % mod;
            }
        }
        return dp[n - 1][k] % mod;
    }

    int numberOfWays(int n, int x) {
        vector<ll> arr;
        ll i = 1;
        while (pow(i, x) <= n) {
            arr.push_back(pow(i, x));
            i++;
        }
        return findWays(arr, n) % mod;
    }
};
