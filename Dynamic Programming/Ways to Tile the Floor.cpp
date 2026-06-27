class Solution {
  public:
    const int mod = 1e9 + 7 ; 
    // Recursion
    int solve(int n , int m){
        if(n == 0)
            return 1 ;
            
        int notTake = solve(n-1 , m ) ; 
        int take = 0 ; 
        if(n>= m)
            take = solve(n-m , m ) ; 
        return (take + notTake) % mod ;    
    }
    
    //Memoization
    int solveMem(int n , int m , vector<int> &dp){
        if(n == 0)
            return 1 ;
        
        if(dp[n] != -1)
            return dp[n] ; 
            
        int notTake = solveMem(n-1 , m , dp) ; 
        int take = 0 ; 
        if(n>= m)
            take = solveMem(n-m , m , dp) ; 
        return dp[n] = (take + notTake) % mod ;    
    }    
    
    // Tabulation
    int solveTab(int n , int m){
        vector<int> dp(n+1 , 0) ; 
        dp[0] = 1 ; 
        for(int i = 1 ; i<= n ; i++){
            int notTake = dp[i-1] ; 
            int take = 0 ; 
            if(i>= m)
                take = dp[i-m] ;
            dp[i] = (take + notTake) % mod ;    
        }
        return dp[n] % mod;
    }
    
    int countWays(int n, int m) {
        // code here.
        if(n < m )
            return 1 ;
        if(n == m )
            return 2 ;
        
        // return solve(n , m) ; 
        // vector<int> dp(n+1 , -1) ;
        // return solveMem(n , m , dp) % mod  ;1
        return solveTab(n , m) ;
    }
};
