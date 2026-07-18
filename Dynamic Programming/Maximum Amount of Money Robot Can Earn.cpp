class Solution {
public:
    int n , m ; 
    int solve(int i , int j , vector<vector<int>> &coins , int k){
        if(i >= n || j >= m)
            return -1e9 ; 

        if(i == n-1 && j == m-1){
            if(coins[i][j] < 0 && k > 0)
                return 0 ; 
            else
                return coins[i][j] ;    
        }

        int take = 0 , notTake = INT_MIN ; 
        take = coins[i][j] + max(solve(i+1 ,j , coins , k) , solve(i , j+1 , coins , k)) ;

        if(coins[i][j] < 0 && k > 0){
            int right = solve(i , j+1 ,coins , k-1) ;
            int down = solve(i+1 , j , coins , k-1) ;

            notTake = max(right , down) ;
        }
        return max(take , notTake) ;   
    }

    int solveMem(int i , int j , vector<vector<int>> &coins , int k , vector<vector<vector<int>>> &dp){
        if(i >= n || j >= m)
            return -1e9 ; 

        if(i == n-1 && j == m-1){
            if(coins[i][j] < 0 && k > 0)
                return 0 ; 
            else
                return coins[i][j] ;    
        }

        if(dp[i][j][k] != -1)
            return dp[i][j][k] ;

        int take = 0 , notTake = INT_MIN ; 
        take = coins[i][j] + max(solveMem(i+1 ,j , coins , k , dp) , solveMem(i , j+1 , coins , k ,dp)) ;

        if(coins[i][j] < 0 && k > 0){
            int right = solveMem(i , j+1 ,coins , k-1 ,dp) ;
            int down = solveMem(i+1 , j , coins , k-1 ,dp) ;

            notTake = max(right , down) ;
        }
        return dp[i][j][k] = max(take , notTake) ;   
    }

    int solveTab(vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp(n+1 ,vector<vector<int>>(m+1 , vector<int>(3 , -1e9))) ;
        for(int k = 0 ; k<3 ; k++){
            if(arr[n-1][m-1] < 0 && k > 0)
                dp[n-1][m-1][k] = 0 ;
            else
                dp[n-1][m-1][k] = arr[n-1][m-1] ;     
        }

        for(int i = n-1 ; i>= 0 ; i--){
            for(int j = m-1 ; j>= 0 ; j--){
                if(i == n-1 && j == m-1)
                    continue ;
                for(int k = 0 ; k< 3 ; k++){
                    int take = arr[i][j] + max(dp[i+1][j][k] , dp[i][j+1][k]) ;
                    int notTake = INT_MIN ; 
                    if(arr[i][j] < 0 && k > 0){
                        notTake = max(dp[i][j+1][k-1] ,dp[i+1][j][k-1]) ; 
                    }
                    dp[i][j][k] = max(take , notTake) ; 
                }
            }
        }        
        return dp[0][0][2] ; 
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n= coins.size() ; 
        m = coins[0].size() ;
        // return solve(0 ,0 , coins , 2) ; 

        vector<vector<vector<int>>> dp(n ,vector<vector<int>>(m , vector<int>(3 , -1))) ; 
        // return solveMem(0 , 0 , coins , 2 , dp) ; 
        return solveTab(coins) ; 
    }
};
