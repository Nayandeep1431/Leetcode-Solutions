class Solution {
    int mod = 1e9+7 ;
    typedef long long ll ;
    int solve(string s , int ind , int k ){
        if(ind >= s.length())
            return 1 ;

        if(s[ind] == '0')
            return 0 ;

        long long num = 0 ;
        int ways = 0 ;
        for(int i = ind ; i<s.length() ; i++){
            num = num * 10 + (s[i] - '0') ;
            if(num > k)
                break ;
            ways = (ways + solve(s , i + 1 , k)) % mod ;
        }
        return ways ;
    }

    //Memoization
    int solveMem(string s , int ind , int k , vector<int> &dp ){
        if(ind >= s.length())
            return 1 ;

        if(s[ind] == '0')
            return 0 ;

        if(dp[ind] != -1)
            return dp[ind] ;

        long long num = 0 ;
        int ways = 0 ;
        for(int i = ind ; i<s.length() ; i++){
            num = num * 10 + (s[i] - '0') ;
            if(num > k)
                break ;
            ways = (ways + solveMem(s , i + 1 , k , dp)) % mod ;
        }
        return dp[ind] = ways ;
    }

    // Tabulation
    int solveTab(string s , int k){
        int n = s.length() ;
        vector<int> dp(n+1 , 0) ;
        dp[n] = 1;

        for(int i = n-1 ; i>=0 ; i--){
            long long num = 0 ;
            int ways = 0 ;
            if(s[i] == '0'){
                dp[i] = 0 ;
                continue ;
            }    

            for(int j = i ; j< n ; j++){
                num = num * 10 + (s[j] - '0') ;
                if(num > k )
                    break ;

                ways = (ways + dp[j+1]) % mod ;    
            }
            dp[i] = ways ;
        }
        return dp[0] ;
    }

public:
    int numberOfArrays(string s, int k) {
        int n = s.length() ;
        // return solve(s, 0 , k) ;

        vector<int> dp(n , -1) ;
        // return solveMem(s , 0 , k , dp) ;

        return solveTab(s , k) ;
    }
};
