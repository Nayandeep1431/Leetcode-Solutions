class Solution {
    // Recursion
    int solve(int ind, vector<int> &nums , int n , int jumps){
        if(ind >= n-1)
            return jumps ;

        int mini = INT_MAX ;
        for(int i =1 ; i<= nums[ind] ; i++){
            mini = min(mini , solve(ind+i , nums ,n , jumps+1)) ;
        }    
        return mini ;
    }

    // Memoization
    int solveMem(int ind, vector<int> &nums , int n , int jumps ,vector<vector<int>> &dp){
        if(ind >= n-1)
            return jumps ;
        if(dp[ind][jumps] != -1)
            return dp[ind][jumps] ;

        int mini = INT_MAX ;
        for(int i =1 ; i<= nums[ind] ; i++){
            mini = min(mini , solveMem(ind+i , nums ,n , jumps+1 , dp)) ;
        }    
        return dp[ind][jumps]=  mini ;
    }

    // Tabulation
    int solveTab(vector<int> &nums){
        int n = nums.size() ;
        vector<vector<int>> dp(n , vector<int> (n+1 , 0)) ;
        for(int ind= n-1 ; ind>=0 ; ind--){
            for(int jumps = n-1; jumps >= 0 ; jumps--){
                int mini = INT_MAX ;
                 for(int i =1 ; i<= nums[ind] ; i++){
                     if(ind + i < n)
                        mini = min(mini , dp[ind+i][jumps+1]) ;
        }
        dp[ind][jumps] = mini ;
            }
        }
        return dp[0][0] ;
    }



public:
    int jump(vector<int>& nums) {
        int ind =0 ;
        int n = nums.size() ;
        // return solve(ind , nums ,n ,0);

        // vector<vector<int>> dp(n , vector<int> (n , -1)) ;
        // return solveMem(0 , nums , n , 0 , dp) ;

        // return solveTab(nums) ;

    }
};
