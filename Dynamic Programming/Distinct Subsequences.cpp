class Solution {
  public:
    // Recursion
    int solve(int i , int j , string &txt , string &pat){
        if(j < 0)
            return 1 ;
        
        if(i < 0)
            return 0 ;
        
        if(txt[i] == pat[j])
            return solve(i-1 , j , txt , pat) + solve(i-1 , j-1 , txt , pat) ;
        else
            return solve(i-1 , j ,txt , pat) ;
    }
    
    // Memoization
    int solveMem(int i , int j , string &txt , string &pat ,vector<vector<int>> &dp){
        if(j < 0)
            return 1 ;
        
        if(i < 0)
            return 0 ;
        
        if(dp[i][j] != -1)
            return dp[i][j] ;
            
        if(txt[i] == pat[j])
            return dp[i][j] = solveMem(i-1 , j , txt , pat ,dp) + solveMem(i-1 , j-1 , txt , pat ,dp) ;
        else
            return dp[i][j] = solveMem(i-1 , j ,txt , pat , dp) ;
    }    
    
    // Tabulation
    int solveTab(string &txt , string &pat){
        int n = txt.size() ;
        int m = pat.size() ;
        
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0)) ;
        for(int i =0 ; i<= n ; i++)
            dp[i][0] = 1 ;
        
        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ;j<= m ; j++){
                if(txt[i-1] == pat[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1] ;
                else
                    dp[i][j] = dp[i-1][j] ;
            }
        }   
        return dp[n][m] ;
    }
    
    int subseqCount(string &txt, string &pat) {
        // code here
        int n = txt.size() ;
        int m = pat.size() ;
        // return solve(n-1 , m-1 , txt ,pat) ;
        
        vector<vector<int>> dp(n , vector<int>(m , -1)) ;
        // return solveMem(n-1 , m-1 , txt ,pat , dp) ;
        
        return solveTab(txt , pat) ;
    }
};
