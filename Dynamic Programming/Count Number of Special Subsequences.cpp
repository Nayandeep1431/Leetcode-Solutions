class Solution {
    int mod = 1e9+7 ;
    // Recursion
    int solve(vector<int> &nums , int ind , int prev){
        if(ind == nums.size()){
            if(prev == 2)
                return 1 ;
            else
                return 0 ;    
        }
        int notTake = solve(nums , ind+1 , prev) ;
        int take = 0;
        if(nums[ind] - prev == 1 || nums[ind] - prev == 0)
            take = solve(nums , ind+1 ,nums[ind]) ;

        return take + notTake ;    
    }

    // Memoization
    int solveMem(vector<int> &nums , int ind , int prev , vector<vector<int>> &dp){
        if(ind == nums.size()){
            if(prev == 2)
                return 1 ;
            else
                return 0 ;    
        }
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1] ;

        int notTake = solveMem(nums , ind+1 , prev , dp) ;
        int take = 0;
        if(nums[ind] - prev == 1 || nums[ind] - prev == 0)
            take = solveMem(nums , ind+1 ,nums[ind] , dp) ;

        return dp[ind][prev+1] = (take + notTake) % mod ;    
    }    

public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size() ;
        int prev = -1 ;
        int ind =0 ;
        // return solve(nums , ind , prev) ;

        vector<vector<int>> dp(n , vector<int> (4 , -1)) ;
        // return solveMem(nums , ind , prev , dp) ;
    }
};
