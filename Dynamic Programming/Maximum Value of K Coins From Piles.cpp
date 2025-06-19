class Solution {
    struct hash_tuple {
    size_t operator()(const tuple<int, int, int>& key) const {
        auto &[a, b, c] = key;
        return hash<int>()(a) ^ (hash<int>()(b) << 1) ^ (hash<int>()(c) << 2);
    }
};

    int solve(vector<vector<int>>& piles, int i , int j , int k){
        if(i >=  piles.size())
            return 0;

        if(k == 0)
            return 0;

        int take = 0;
        if (j < (int)piles[i].size())
            take = piles[i][j] + solve(piles, i, j + 1, k - 1);
        else
            take = solve(piles, i + 1, 0, k);

        int skip = solve(piles, i + 1, 0, k);  

        return max(take, skip);
    }

int solveMem(vector<vector<int>>& piles, int i , int j , int k , vector<vector<vector<int>>>& dp ){
    if(i >= piles.size() || k == 0)
        return 0;

    if(dp[i][j][k] != -1)
        return dp[i][j][k];

    int take = 0;
    if (j < piles[i].size())
        take = piles[i][j] + solveMem(piles, i, j + 1, k - 1, dp);
    else
        take = solveMem(piles, i + 1, 0, k, dp);

    int skip = solveMem(piles, i + 1, 0, k, dp);

    return dp[i][j][k] = max(take, skip);
}


public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // return solve(piles , 0 , 0 , k);

           int n = piles.size();
         int m = 0;
            for (auto& pile : piles)
        m = max(m, (int)pile.size());

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    return solveMem(piles, 0, 0, k, dp);
    }
};
