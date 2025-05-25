class Solution {
    bool solve(int ind1 , int ind2 , int ind , string s1 , string s2 , string s){
        if(ind >= s.length())
            return true ;

        if(s1[ind1] != s[ind] && s2[ind2] != s[ind])
            return false ;
        bool first ;
        bool second ;
        if(s[ind] == s1[ind1])
            first = solve(ind1 + 1 , ind2 , ind+1 ,s1,s2,s) ;

        if(s[ind] == s2[ind2])
            second = solve(ind1 ,ind2+1 , ind+1 , s1 , s2 , s) ;

        return first || second ;             
    }
// Memoization
        bool solveMem(int ind1 , int ind2 , int ind , string s1 , string s2 , string s , vector<vector<vector<int>>> &dp){
        if(ind >= s.length())
            return true ;

        if(s1[ind1] != s[ind] && s2[ind2] != s[ind])
            return false ;

        if(dp[ind1][ind2][ind] != -1)    
            return dp[ind1][ind2][ind] ;
        bool first ;
        bool second ;
        if(s[ind] == s1[ind1])
            first = solveMem(ind1 + 1 , ind2 , ind+1 ,s1,s2,s , dp) ;

        if(s[ind] == s2[ind2])
            second = solveMem(ind1 ,ind2+1 , ind+1 , s1 , s2 , s , dp) ;

        return dp[ind1][ind2][ind] = first || second ;             
    }

// Tabulation
     bool solveTab(string &s1, string &s2, string &s) {
        int n = s1.length(), m = s2.length(), o = s.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i < n && s[i + j] == s1[i])
                    dp[i + 1][j] = dp[i + 1][j] || dp[i][j];
                if (j < m && s[i + j] == s2[j])
                    dp[i][j + 1] = dp[i][j + 1] || dp[i][j];
            }
        }

        return dp[n][m];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false ;   
        // return solve(0 , 0 , 0 ,s1 ,s2 , s3) ;

        int n = s1.length() ;
        int m = s2.length() ;
        int o = s3.length() ;
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>> (m+1 , vector<int> (o+1 , -1))) ;
        // return solveMem(0,0,0,s1,s2,s3,dp) ;

        return solveTab(s1, s2, s3);
    }
};
