class Solution {
  public:
    const int mod = 1e9 + 7 ; 
    
    // Recursion 
    int solve(int n , int i){
        if(n == 0)
            return 1 ; 
        if(i == 0)
            return 0 ;
            
        int nottake = solve(n , i-1) ; 
        int take = 0 ;
        if (n >= i)
            take = solve(n-i , i) ; 
        return (take + nottake) % mod ;    
    }
    
    // Memoization
    int solveMem(int n , int i , vector<vector<int>> &dp){
        if(n == 0)
            return 1 ; 
        if(i == 0)
            return 0 ;
        if(dp[n][i] != -1)
            return dp[n][i] ; 
        int nottake = solveMem(n , i-1 , dp) ; 
        int take = 0 ;
        if (n >= i)
            take = solveMem(n-i , i , dp) ; 
        return dp[n][i] = (take + nottake) % mod ;    
    }  
    
    // Tabulation
    int solveTab(int n){
        vector<vector<int>> dp(n+1 , vector<int> (n , 0)) ; 
        for(int i = 0 ; i< n ; i++)
            dp[0][i] = 1 ; 
        for(int i = 0 ; i<= n ; i++)
            dp[i][0] = 0 ;
        
        for(int i =1 ; i<= n ; i++ ){
            for(int j = 1 ; j< n ; j++){
                int notTake = dp[i][j-1] ; 
                int take = 0 ; 
                if(i >= j)
                    take = dp[i-j][j] ; 
                dp[i][j] = (take + notTake) % mod ;    
            }
        }    
        return dp[n][n-1] % mod ;
    }
    
    int countWays(int n) {
        // return solve(n , n-1) % mod ;
        
        // vector<vector<int>> dp(n+1 , vector<int>(n , -1)) ; 
        // return solveMem(n , n-1 , dp) % mod ; 
        
        return solveTab(n) % mod ;
    }
};
