class Solution {
    // Recursion
    int solve(vector<int> &arr, int i, int j) {
        if (i + 1 == j)
            return 0;

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int val = arr[i] * arr[j] * arr[k] + solve(arr, i, k) + solve(arr, k, j);
            ans = min(ans, val);
        }
        return ans;
    }

    // Memoization
    int solveMem(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i + 1 == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int val = arr[i] * arr[j] * arr[k] + solveMem(arr, i, k, dp) + solveMem(arr, k, j, dp);
            ans = min(ans, val);
        }
        return dp[i][j] = ans;
    }

    // Tabulation
    int solveTab(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int val = nums[i] * nums[j] * nums[k] + dp[i][k] + dp[k][j];
                    ans = min(ans, val);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        // Option 1: Plain recursion (not recommended for large inputs)
        // return solve(values, 0, n - 1);

        // Option 2: Memoization
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMem(values, 0, n - 1, dp);

        // Option 3: Tabulation (Best performance)
        return solveTab(values);
    }
};
