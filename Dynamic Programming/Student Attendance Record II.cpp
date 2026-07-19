class Solution {
public:
    int mod = 1e9 + 7 ; 
    int solve(int ind , int abs , int cnt ){
        if(abs >= 2 || cnt >= 3)
            return 0 ;

        if(ind == 0)
            return 1 ;

        int A = solve(ind - 1 , abs + 1 , 0) ; 
        int P = solve(ind-1 , abs , 0) ; 
        int L = solve(ind-1 , abs ,cnt + 1) ;

        return ((L + P) % mod + A) % mod ;         
    }

    int solveMem(int ind , int abs , int cnt , vector<vector<vector<int>>> &dp ){
        if(abs >= 2 || cnt >= 3)
            return 0 ;

        if(ind == 0)
            return 1 ;

        if(dp[ind][abs][cnt] != -1)
            return dp[ind][abs][cnt] ; 

        int A = solveMem(ind - 1 , abs + 1 , 0 , dp) ; 
        int P = solveMem(ind-1 , abs , 0 , dp) ; 
        int L = solveMem(ind-1 , abs ,cnt + 1 ,dp) ;

        return dp[ind][abs][cnt] = ((L + P) % mod + A) % mod ;         
    }    
    int checkRecord(int n) {
        // return solve(n , 0 , 0) ;
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int> (3 , -1))) ; 
        return solveMem(n , 0 , 0 , dp) ;

    }
};
