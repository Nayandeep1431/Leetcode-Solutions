// Recursion
int solve(vector<int> &arr, int ind, int prev_ind, int n) {
    if (ind == n)
        return 0;

    int notTake = solve(arr, ind + 1, prev_ind, n);
    int take = 0;
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
        take = 1 + solve(arr, ind + 1, ind, n);

    return max(take, notTake);
}

// Memoization
int solveMem(vector<int> &arr, int ind, int prev_ind, int n, vector<vector<int>> &dp) {
    if (ind == n)
        return 0;

    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int notTake = solveMem(arr, ind + 1, prev_ind, n, dp);
    int take = 0;
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
        take = 1 + solveMem(arr, ind + 1, ind, n, dp);

    return dp[ind][prev_ind + 1] = max(take, notTake);
}

// Tabulation
int lisTabulation(vector<int> &arr, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
            int notTake = dp[ind + 1][prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take = 1 + dp[ind + 1][ind + 1];

            dp[ind][prev_ind + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

// Driving function
int lis(vector<int> &arr, int n) {
    // Recursion
    // return solve(arr, 0, -1, n);

    // Memoization
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return solveMem(arr, 0, -1, n, dp);

    // Tabulation
    return lisTabulation(arr, n);
}
