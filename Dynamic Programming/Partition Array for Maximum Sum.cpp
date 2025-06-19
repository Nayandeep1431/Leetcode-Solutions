class Solution {
public:
    int n ;
    // Recursion
    int solve(int ind , vector<int> &arr , int k){
        if(ind >= n)
            return 0 ;

        int res = 0 ;
        int currMax = -1 ;
        for(int i = ind ; i< n && i-ind+1 <= k ; i++){
            currMax = max(currMax , arr[i]) ;
            res = max(res , (i-ind+1) * currMax + solve(i+1 , arr , k)) ;
        }    
        return res ;
    }

    //  Memoization
    int solveMem(int ind , vector<int> &arr , int k ,vector<int> &dp){
        if(ind >= n)
            return 0 ;

        if(dp[ind] != -1)
            return dp[ind] ;
            
        int res = 0 ;
        int currMax = -1 ;
        for(int i = ind ; i< n && i-ind+1 <= k ; i++){
            currMax = max(currMax , arr[i]) ;
            res = max(res , (i-ind+1) * currMax + solveMem(i+1 , arr , k , dp)) ;
        }    
        return dp[ind] = res ;
    }

    // Tabulation
    int solveTab(vector<int> &arr , int k){
        vector<int> dp(n+1 , 0) ;
        for(int ind = n-1 ; ind >=0 ; ind--){
            int res = 0 ;
            int currMax = -1 ;
            for(int j = ind ; j< n && j - ind +1 <= k ; j++){
                currMax = max(currMax , arr[j]) ;
                res = max(res , (j - ind +1) * currMax + dp[j+1]) ;
            }
            dp[ind] = res ;
        }
        return dp[0] ;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size() ;
        // return solve(0 , arr, k ) ;

        vector<int> dp(n , -1) ;
        // return solveMem(0 ,arr , k , dp) ;

        return solveTab(arr , k) ;
    }
};
