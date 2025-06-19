class Solution {
public:
    int n ;
    // Recursion
    int solve(string s, int ind , int prev){
        if(ind >= n)
            return 0 ;

        int flip = INT_MAX ;
        int noflip = INT_MAX ;

        if(s[ind] == '0'){
            if(prev == 1)
                flip = 1 + solve(s , ind+1 , 1) ;
            else{
                flip = 1 + solve(s , ind+1 , 1) ;
                noflip = solve(s , ind+1 , 0) ;
            }    
        }   
        else if(s[ind] == '1' ){
            if(prev == 0){
                flip = 1+ solve(s , ind+1, 0) ;
                noflip = solve(s , ind+1 ,1) ;
            }
            else{
                noflip = solve(s , ind+1 , 1 ) ;
            }
        } 
        return min(flip , noflip) ;
    }

    // Memoization
    int solveMem(string s, int ind , int prev , vector<vector<int>> &dp){
        if(ind >= n)
            return 0 ;

        if(dp[ind][prev] != -1)
            return dp[ind][prev] ;

        int flip = 1e9 ;
        int noflip = 1e9 ;

        if(s[ind] == '0'){
            if(prev == 1)
                flip = 1 + solveMem(s , ind+1 , 1 , dp) ;
            else{
                flip = 1 + solveMem(s , ind+1 , 1 , dp) ;
                noflip = solveMem(s , ind+1 , 0 , dp) ;
            }    
        }   
        else if(s[ind] == '1' ){
            if(prev == 0){
                flip = 1+ solveMem(s , ind+1, 0 , dp) ;
                noflip = solveMem(s , ind+1 ,1 , dp) ;
            }
            else{
                noflip = solveMem(s , ind+1 , 1 , dp ) ;
            }
        } 
        return dp[ind][prev] = min(flip , noflip) ;
    }

    // Tabulation
    int solveTab(string s){
         vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int prev = 0; prev <= 1; ++prev) {
                int flip = 1e9, noflip = 1e9;

                if (s[i] == '0') {
                    if (prev == 1) {
                        flip = 1 + dp[i + 1][1];
                    } else {
                        flip = 1 + dp[i + 1][1];
                        noflip = dp[i + 1][0];
                    }
                } else {
                    if (prev == 0) {
                        flip = 1 + dp[i + 1][0];
                        noflip = dp[i + 1][1];
                    } else {
                        noflip = dp[i + 1][1];
                    }
                }

                dp[i][prev] = min(flip, noflip);
            }
        }

        return dp[0][0];
    }
    

    int minFlipsMonoIncr(string s) {
        n = s.length() ;
        // return solve(s , 0 , 0) ;
        vector<vector<int>> dp(n , vector<int> (2 , -1)) ;
        // return solveMem(s , 0 , 0 , dp) ;

        return solveTab(s) ;
    }
};
