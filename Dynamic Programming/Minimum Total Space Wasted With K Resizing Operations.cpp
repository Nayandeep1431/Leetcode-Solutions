class Solution {
    int solve(int ind, vector<int> &nums, int k, vector<vector<int>> &dp, int n) {
        if (ind == n)
            return 0;

        if (k < 0)
            return 1e9+7;

        if (dp[ind][k] != -1)
            return dp[ind][k];

        int maxi = 0;
        int sum = 0;
        int cost = 1e9+7;

        for (int j = ind; j < n; j++) {
            maxi = max(maxi, nums[j]);
            sum += nums[j];
            int wasted = (j - ind + 1) * maxi - sum;
            cost = min(cost, wasted + solve(j + 1, nums, k - 1, dp, n));
        }

        return dp[ind][k] = cost;
    }

public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 2, -1)); // k+2 to be safe
        return solve(0, nums, k, dp, n);
    }
};
