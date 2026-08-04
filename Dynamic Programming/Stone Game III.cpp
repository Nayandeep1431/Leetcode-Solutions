class Solution {
public:
    int n ;
    // Recursion
    int solve(int ind , vector<int> &arr){
        if(ind >= n)
            return 0 ; 

        int res = INT_MIN ; 
        res = max(res , arr[ind] - solve(ind+1 , arr)) ; 
        if(ind + 1 < n)
            res = max(res , arr[ind] + arr[ind+1] - solve(ind+2 ,arr)) ; 
        if(ind + 2 < n)
            res = max(res ,arr[ind] + arr[ind+1] + arr[ind+2] - solve(ind+3 ,arr) )  ;

        return res ;           
    }

    // Memoization
    int solveMem(int ind , vector<int> &arr , vector<int> &dp){
        if(ind >= n)
            return 0 ; 

        if(dp[ind] != -1)
            return dp[ind] ; 

        int res = INT_MIN ; 
        res = max(res , arr[ind] - solveMem(ind+1 , arr , dp)) ; 
        if(ind + 1 < n)
            res = max(res , arr[ind] + arr[ind+1] - solveMem(ind+2 ,arr , dp)) ; 
        if(ind + 2 < n)
            res = max(res ,arr[ind] + arr[ind+1] + arr[ind+2] - solveMem(ind+3 ,arr ,dp) )  ;

        return dp[ind] = res ;           
    }

    // Tabulation
    int solveTab( vector<int> &arr ){
        vector<int> dp(n+1 ,0) ; 
 
        for(int i = n-1 ; i>=  0 ; i--){
            int res = INT_MIN ; 
            res = max(res , arr[i] - dp[i+1]) ; 
            if(i + 2 <= n)
                res = max(res , arr[i] + arr[i+1] - dp[i+2]); 
            if(i + 3 <= n)
                res = max(res ,arr[i] + arr[i+1] + arr[i+2] - dp[i+3] ) ;

            dp[i] = res ; 
        }
        return dp[0] ;           
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size() ; 
        // int diff = solve(0 , stoneValue) ; 

        // vector<int> dp(n+1 , -1) ; 
        // int diff = solveMem(0 , stoneValue , dp) ; 

        int diff = solveTab(stoneValue) ; 
        if(diff < 0)
            return "Bob" ; 
        else if(diff > 0)
            return "Alice" ; 
        return "Tie" ;        
    }
};
