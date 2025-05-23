class Solution {
    // Recursion
    int solve(vector<int> &arr, int ind, int time) {
        if (ind == arr.size())
            return 0;

        int include = arr[ind] * (time + 1) + solve(arr, ind + 1, time + 1);
        int exclude = solve(arr, ind + 1, time);
        return max(include, exclude);
    }

    // Memoization
    int solveMem(vector<int> &arr, int ind, int time, vector<vector<int>> &dp) {
        if (ind == arr.size())
            return 0;
        if (dp[ind][time] != -1)
            return dp[ind][time];

        int include = arr[ind] * (time + 1) + solveMem(arr, ind + 1, time + 1, dp);
        int exclude = solveMem(arr, ind + 1, time, dp);
        return dp[ind][time] = max(include, exclude);
    }

    // Tabulation
    int solveTab(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int time = ind; time >= 0; time--) {
                int include = arr[ind] * (time + 1) + dp[ind + 1][time + 1];
                int exclude = dp[ind + 1][time];
                dp[ind][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        // Option 1: Recursion
        // return solve(satisfaction, 0, 0);

        // Option 2: Memoization
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solveMem(satisfaction, 0, 0, dp);

        // Option 3: Tabulation (best for performance)
        return solveTab(satisfaction);
    }
};
