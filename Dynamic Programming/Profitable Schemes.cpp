class Solution {
    typedef long long ll;
    int m;
    int mod = 1e9 + 7;

    int solve(int ind, int p, int people, int minProfit, vector<int>& gr, vector<int>& pr
    ,vector<vector<vector<int>>> &dp) {
        if (ind == gr.size()) {
            if (p >= minProfit)
                return 1;
            return 0;
        }

        if (people > m)
            return 0;

        if(dp[ind][p][people] != -1)
            return dp[ind][p][people] ;

        ll nottake = solve(ind + 1, p, people, minProfit, gr, pr , dp);
        ll take = 0;

        if (people + gr[ind] <= m) 
            take = solve(ind + 1, min(p + pr[ind], minProfit), people + gr[ind], minProfit, gr, pr ,dp);

        return dp[ind][p][people] = (take + nottake) % mod;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        m = n; 
        // return solve(0, 0, 0, minProfit, group, profit);

        vector<vector<vector<int>>> dp(101 , vector<vector<int>> (101 , vector<int>(101 ,-1))) ;
         return solve(0, 0, 0, minProfit, group, profit , dp);
    }
};
