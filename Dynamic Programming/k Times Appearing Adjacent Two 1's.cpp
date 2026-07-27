class Solution {
  public:
    const int mod = 1e9 + 7 ;
    
    int solve(int ind , int k , int prev , int n){
        if(ind > n)
            return (k == 0) ? 1 : 0 ; 
        
        if(k < 0)
            return 0 ; 
            
        int one = (prev == 1) ? solve(ind +1, k-1 , 1 , n) : solve(ind+1 , k , 1 , n) ; 
        int zero = solve(ind+1 , k , 0, n) ;
        
        return (one + zero) % mod ;
    }
    
    int solveMem(int ind , int k , int prev , int n ,vector<vector<vector<int>>> &dp){
        if(ind > n)
            return (k == 0) ? 1 : 0 ; 
            
        if(k < 0)
            return 0 ; 
        
        if(dp[ind][k][prev] != -1)
            return dp[ind][k][prev] ; 
            
        int one = (prev == 1) ? solveMem(ind +1, k-1 , 1 , n , dp) : solveMem(ind+1 , k , 1 , n , dp) ; 
        int zero = solveMem(ind+1 , k , 0, n ,dp) ;
        
        return  dp[ind][k][prev] = (one + zero) % mod ;
    }
    
    int countStrings(int n, int k) {
        // code here
        // int one = solve(2 , k , 1 , n) % mod ;
        // int zero = solve(2 , k , 0 , n) % mod ; 
        
        // return (one + zero) % mod ; 
        
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(k+1 ,vector<int>(2 , -1) )) ;
        int one = solveMem(2 , k , 1 , n , dp) % mod ;
        int zero = solveMem(2 , k , 0 , n , dp) % mod ; 
        
        return (one + zero) % mod ; 
    }
};
