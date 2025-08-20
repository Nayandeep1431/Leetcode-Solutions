class Solution {
public:
    // Memoization
    int solveMem(vector<vector<int>>& mat , int i , int j , vector<vector<int>> &dp){
        if(i >= mat.size() ||  j >= mat[0].size())
            return 0 ;
        if(dp[i][j] != -1)
            return dp[i][j] ;

        int right = solveMem(mat , i+1 , j , dp) ;
        int down = solveMem(mat , i , j+1 , dp) ;
        int diag = solveMem(mat , i+1 , j+1 , dp) ;

        if(mat[i][j] == 1){
            int val = min({right , down , diag}) ;
            dp[i][j] = 1 + val ;
            return dp[i][j] ;
        }        
        else
           return dp[i][j] = 0 ;
    }

    int countSquares(vector<vector<int>>& matrix){
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        vector<vector<int>>dp(n , vector<int> (m ,-1)) ;
        solveMem(matrix , 0 , 0 , dp) ;

        int ans = 0 ;
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j< m ; j++){
                cout<<dp[i][j]<<" " ; 
                ans += dp[i][j] ;
            }
            cout<<endl ;
        }
        return ans ;
    }

    // Tabulation
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        vector<vector<int>> dp(n , vector<int>(m , 0)) ;
        for(int i =0 ; i< m ; i++){
            dp[0][i] = matrix[0][i] ;
        }
        for(int i =0 ; i< n ; i++)
            dp[i][0] = matrix[i][0] ;

        for(int i = 1 ; i< n ; i++){
            for(int j =1 ; j< m ; j++){
                if (matrix[i][j] == 0) dp[i][j] = 0;
               else{ 
                int val = min({dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]}) ;
                dp[i][j] = 1 + val ;
               }
            }
        }    
        int ans = 0 ;
        for(int i =0 ;i< n ; i++){
            for(int j =0 ; j< m ; j++){
                cout<< dp[i][j]<<" ";
                ans += dp[i][j] ;
            }
            cout<<endl ;
        }
        return ans ;
    }
};
