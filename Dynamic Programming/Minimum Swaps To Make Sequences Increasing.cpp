class Solution {
public:
    // Recursion
    int solve(vector<int> &nums1, vector<int> &nums2, int index, int swapped) {
        if (index == nums1.size()) return 0;

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped) swap(prev1, prev2);

        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, 0);

        // swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));

        return ans;
    }

    // Memoization
    int solveMem(vector<int> &nums1, vector<int> &nums2, int index, int swapped, vector<vector<int>> &dp) {
        if (index == nums1.size()) return 0;
        if (dp[index][swapped] != -1) return dp[index][swapped];

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped) swap(prev1, prev2);

        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveMem(nums1, nums2, index + 1, 0, dp);

        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solveMem(nums1, nums2, index + 1, 1, dp));

        return dp[index][swapped] = ans;
    }

    // Tabulation
    int solveTab(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        for (int i = n - 1; i >= 1; i--) {
            for (int swapped = 0; swapped <= 1; swapped++) {
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];
                if (swapped) swap(prev1, prev2);

                int ans = INT_MAX;

                // No swap
                if (nums1[i] > prev1 && nums2[i] > prev2)
                    ans = dp[i + 1][0];

                // Swap
                if (nums1[i] > prev2 && nums2[i] > prev1)
                    ans = min(ans, 1 + dp[i + 1][1]);

                dp[i][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Recursion:
        // return solve(nums1, nums2, 1, 0);

        // Memoization:
        return solveMem(nums1, nums2, 1, 0, dp);

        // Tabulation:
        // return solveTab(nums1, nums2);
    }
};
