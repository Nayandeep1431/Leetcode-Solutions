// User function Template for C++

class Solution {
    // Recursion
    int solve(vector<int> &price , int n){
        if(n < 0)
            return -1e9 ;
        
        if(n == 0)
            return 0 ;
        
        int ans = INT_MIN ;
        for(int i = 0 ; i< n ; i++){
            int val = solve(price , n - (i+1)) ;
            ans = max(ans , price[i] + val) ;
        }
        return ans ;
    }
    
    //  Memoization
    int solveMem(vector<int> &price , int n ,vector<int> &dp){
        if(n < 0)
            return -1e9 ;
        
        if(n == 0)
            return 0 ;
        if(dp[n] != -1)
            return dp[n] ;
            
        int ans = INT_MIN ;
        for(int i = 0 ; i< n ; i++){
            int val = solveMem(price , n - (i+1) ,dp) ;
            ans = max(ans , price[i] + val) ;
        }
        return dp[n] = ans ;
    }
    
    // Tabulation
    int solveTab(vector<int> &price , int n){
        vector<int> dp(n+1 , 0) ;
        dp[0] = 0 ;
        
        for(int i = 1; i <= n; i++) {
            int ans = INT_MIN;
            for(int j = 0; j < price.size(); j++) {
                int cutLen = j + 1;
                if(i - cutLen >= 0) {
                    ans = max(ans, price[j] + dp[i - cutLen]);
                }
            }
            dp[i] = ans;
        }

        return dp[n];
    }
    
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size() ;

        // return solve(price , n) ; // Recursion
        //  vector<int> dp(n+1 , -1) ;
        // return solveMem(price , n , dp) ; Memoization
        
        // Tabulation
        return solveTab(price , n) ;
        
    }
};
