class Solution {
public:
    int mod = 1e9 + 7 ;
    // Recursion
    int solve(int day , int delay , int f){
        if(day == 1)
            return 1 ;

        int res = 0 ;
        for(int i= day - f+1 ; i<= day - delay ; i++ ){
            if(i > 0)
                res = (res + solve(i , delay , f)) % mod ;
        }    
        return res ;
    }

    // Memoization
    int solveMem(int day , int delay , int f , vector<int> &dp){
        if(day == 1)
            return 1 ;

        if(dp[day] != -1)
            return dp[day] ;
        int res = 0 ;
        for(int i= day - f+1 ; i<= day - delay ; i++ ){
            if(i > 0)
                res = (res + solveMem(i , delay , f , dp)) % mod ;
        }    
        return dp[day] = res ;
    }

    // Tabulation
    int solveTab(int n , int delay , int f){
        vector<int> dp(n+1 , 0) ;
        dp[1] = 1 ;
        for(int day = 2 ; day<= n ; day++){
            int res = 0 ;
            for(int i = day - f + 1 ; i <= day - delay ; i++){
                if(i > 0)
                    res = (res + dp[i]) % mod ;
            }
            dp[day] = res ;
        }

        int cnt = 0 ;
        for(int i = n- f + 1 ; i<= n ; i++){
            if(i > 0)
                cnt = (cnt + dp[i]) % mod ;
        }
        return cnt  ;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int res = 0 ;
        return solveTab(n , delay ,forget) ;
        // for(int i = n - forget+1 ; i<= n ; i++){
        //     if(i > 0)
        //         res = (res + solveMem(i , delay , forget ,dp)) % mod ;
        //         // res = (res + solve(i , delay , forget)) % mod ;
        // }
        // return res ;
    }
};
