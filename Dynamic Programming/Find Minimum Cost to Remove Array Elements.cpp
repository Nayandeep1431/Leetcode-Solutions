class Solution {
public:
    int solve(int prev , int ind, vector<int> &nums , vector<vector<int>> &dp){
        if(ind == nums.size())
            return nums[prev] ;
        if(ind == nums.size() - 1)
            return max(nums[ind] , nums[prev]) ;

        if(dp[prev][ind] != -1)
            return dp[prev][ind] ;    

        int op1 = max(nums[ind] , nums[ind+1]) + solve(prev , ind+2 , nums , dp) ;
        int op2 = max(nums[prev] , nums[ind]) + solve(ind+1 , ind+2 , nums , dp) ;
        int op3 = max(nums[prev] , nums[ind+1]) + solve(ind , ind+2 , nums , dp) ;

        return dp[prev][ind] = min({op1 , op2 , op3}) ;        
    }
    int minCost(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n , vector<int> (n , -1)) ;
        return solve(0 , 1 , nums , dp) ;
    }
};
