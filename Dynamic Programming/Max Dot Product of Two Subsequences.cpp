class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<int>& nums2) {
        if (i == nums.size() || j == nums2.size())
            return INT_MIN;

        int val = nums[i] * nums2[j];
        int next = solve(i + 1, j + 1, nums, nums2);
        int take = val;
        if (next != INT_MIN)
            take += next;

        take = max(take, val); 
        int skip_i = solve(i + 1, j, nums, nums2);
        int skip_j = solve(i, j + 1, nums, nums2);

        return max({take, skip_i, skip_j});
    }

    int solveMem(int i, int j, vector<int>& nums, vector<int>& nums2 , vector<vector<int>> &dp) {
        if (i == nums.size() || j == nums2.size())
            return INT_MIN;

        if(dp[i][j] != -1e9)
            return dp[i][j] ;
        int val = nums[i] * nums2[j];
        int next = solveMem(i + 1, j + 1, nums, nums2 ,dp);
        int take = val;
        if (next != INT_MIN)
            take += next;

        take = max(take, val); 
        int skip_i = solveMem(i + 1, j, nums, nums2 , dp);
        int skip_j = solveMem(i, j + 1, nums, nums2 , dp);

        return dp[i][j] = max({take, skip_i, skip_j});
    }

    // Tabulation
    int solveTaab(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int prod = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = max({
                    prod,                             
                    dp[i - 1][j - 1] + prod,          
                    dp[i - 1][j],                  
                    dp[i][j - 1]                     
                });
            }
        }

        return dp[n][m];
    }



    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // return solve(0, 0, nums1, nums2);

        int n = nums1.size() ;
        int m = nums2.size() ;
        vector<vector<int>> dp(n ,vector<int> (m ,-1e9)) ;
        return solveMem(0 , 0 , nums1 , nums2 , dp) ;
    }
};
