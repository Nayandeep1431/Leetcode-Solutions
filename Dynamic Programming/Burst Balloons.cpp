class Solution {
public:
      // recursion
      int solve(int i , int j , vector<int> &nums){
        if(i > j)
            return 0 ;

        int maxi = INT_MIN ;
        for(int k = i ; k<= j ; k++){
            int val = solve(i , k-1 , nums ) + solve(k+1 , j, nums) + nums[i-1] * nums[k] * nums[j+1] ;
            maxi = max(maxi , val) ;
        }    
        return maxi ;
    }
// Memoization
    int solveMem(int i , int j , vector<int> &nums , vector<vector<int>> &dp){
        if(i > j)
            return 0 ;
        
        if(dp[i][j] != -1)
            return dp[i][j] ;
        int maxi = INT_MIN ;
        for(int k = i ; k<= j ; k++){
            int val = solveMem(i , k-1 , nums , dp ) + solveMem(k+1 , j, nums , dp) + nums[i-1] * nums[k] * nums[j+1] ;
            maxi = max(maxi , val) ;
        }    
        return dp[i][j] = maxi ;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size() ;
        nums.insert(nums.begin() , 1) ;
        nums.push_back(1) ;
        // return solve(1 , n , nums) ;
        vector<vector<int>> dp(n+2  , vector<int> (n+2 , -1)) ;
        return solveMem(1 , n , nums, dp) ;
    }
};
