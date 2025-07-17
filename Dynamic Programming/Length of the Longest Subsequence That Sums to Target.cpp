class Solution {
public:
    // Recursion
    int solve(int ind, int target, vector<int> &nums) {
        if (target == 0)
            return 0;
        if (ind == nums.size())
            return INT_MIN; // impossible path

        int take = INT_MIN;
        if (nums[ind] <= target)
            take = 1 + solve(ind + 1, target - nums[ind], nums);

        int notTake = solve(ind + 1, target, nums);

        return max(take, notTake);
    }

    // Memoization
    int solveMem(int ind, int target, vector<int> &nums ,vector<vector<int>> &dp) {
        if (target == 0)
            return 0;
        if (ind == nums.size())
            return INT_MIN; 

        if(dp[ind][target] != -1)
            return dp[ind][target] ;
        int take = INT_MIN;
        if (nums[ind] <= target)
            take = 1 + solveMem(ind + 1, target - nums[ind], nums ,dp);

        int notTake = solveMem(ind + 1, target, nums ,dp);

        return dp[ind][target] = max(take, notTake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size() ;
        // int ans = solve(0, target, nums);
        // return (ans < 0 ? -1 : ans); 

        vector<vector<int>> dp(n , vector<int> (target+1 , -1)) ;
        int ans = solveMem(0, target, nums ,dp);
        return (ans < 0 ? -1 : ans); 
    }
};
