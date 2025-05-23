class Solution {
    // Recursion
    int solve(int start , int end , vector<int>&slices ,int n){
        if(n == 0 || start > end)
            return 0 ;

        int take = slices[start] + solve(start+2 , end , slices ,n-1) ;
        int notTake = solve(start+1 , end , slices , n) ;
        return max(take , notTake) ;    
    }

    // Memoization
    int solveMem(int start , int end , vector<int>&slices ,int n , vector<vector<int>> &dp){
        if(n == 0 || start > end)
            return 0 ;
        if(dp[start][n] != -1)
            return dp[start][n] ;

        int take = slices[start] + solveMem(start+2 , end , slices ,n-1 ,dp) ;
        int notTake = solveMem(start+1 , end , slices , n , dp) ;
        return dp[start][n] = max(take , notTake) ;    
    }    

    // Tabulation
    int solve(vector<int> &slices){
        int k = slices.size() ;
        int n = k / 3 ;
        vector<vector<int>> dp1(k + 2, vector<int>(n + 1, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(n + 1, 0));

        // Exclude last slice: index 0 to k-2
        for(int i = k - 2 ; i >= 0 ; i--){
            for(int j = 1; j <= n ; j++){
                int take = slices[i] + dp1[i + 2][j - 1];
                int notTake = dp1[i + 1][j];
                dp1[i][j] = max(take , notTake);
            }
        }

        // Exclude first slice: index 1 to k-1
        for(int i = k - 1 ; i >= 1 ; i--){
            for(int j = 1; j <= n ; j++){
                int take = slices[i] + dp2[i + 2][j - 1];
                int notTake = dp2[i + 1][j];
                dp2[i][j] = max(take , notTake);
            }
        }

        int ans1 = dp1[0][n];
        int ans2 = dp2[1][n];
        return max(ans1 , ans2);      
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size() ;

        // Recursion
        // int case1 = solve(0 , k - 2 , slices , k / 3) ;
        // int case2 = solve(1 , k - 1 , slices , k / 3) ;
        // // return max(case1 , case2) ;

        // // Memoization
        // vector<vector<int>> dp1(k, vector<int>(k / 3 + 1, -1)) ;
        // int ans1 = solveMem(0 , k - 2 , slices , k / 3 , dp1) ;
        // vector<vector<int>> dp2(k, vector<int>(k / 3 + 1, -1)) ;
        // int ans2 = solveMem(1 , k - 1 , slices , k / 3 , dp2) ;  
        // // return max(ans1 , ans2) ;    

        // Tabulation
        return solve(slices) ;  
    }
};
