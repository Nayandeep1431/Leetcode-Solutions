

class Solution {
public:
    unordered_map<int, int> mpp;
    int n;
    vector<vector<int>> dp;

    bool solve(int ind, int k, vector<int>& stones) {   
        if (ind == n - 1) 
            return true;
        if (dp[ind][k] != -1) 
            return dp[ind][k];

        int jumps[3] = {k - 1, k, k + 1};

        for (int i = 0; i < 3; i++) {
            if (jumps[i] <= 0) continue;
            
            int pos = stones[ind] + jumps[i];
            if (mpp.find(pos) != mpp.end()) {
                if (solve(mpp[pos], jumps[i], stones))
                    return dp[ind][k] = true;
            }
        }
        return dp[ind][k] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (n <= 1) return true;
        if (stones[1] - stones[0] <= 0) return false;

        for (int i = 0; i < n; i++)
            mpp[stones[i]] = i;

        int max_jump = n;
        dp.assign(n, vector<int>(max_jump + 1, -1));

        if(stones[1] - stones[0] > 1)
            return false ;
        return solve(1, 1, stones);
    }
};
