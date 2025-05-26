class Solution {
    // recursion
    int solve(vector<vector<char>> &mat , int i , int j , int &maxi){
        if(i >= mat.size() || j >= mat[0].size())
            return 0 ;

        int right = solve(mat , i , j+1 , maxi) ;
        int diagonal = solve(mat , i+1 ,j+1 , maxi) ;
        int bottom = solve(mat , i+1 , j , maxi) ;

        if(mat[i][j] == '1'){
            int ans = 1 + min({right , bottom , diagonal}) ;
            maxi = max(maxi , ans) ;
            return ans ;
        }    
        else
            return 0 ;
    }

    // Memoization
     int solveMem(vector<vector<char>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp) {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solveMem(mat, i, j + 1, maxi, dp);
        int diagonal = solveMem(mat, i + 1, j + 1, maxi, dp);
        int down = solveMem(mat, i + 1, j, maxi, dp);

        if (mat[i][j] == '1') {
            dp[i][j] = 1 + min({right, diagonal, down});
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        } else {
            return dp[i][j] = 0;
        }
    }

    // Tabulation
    int solveTab(vector<vector<char>>& mat){
        int n = mat.size() ;
        int m = mat[0].size() ;
        int maxi = 0 ;
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0)) ;
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >=0 ; j--){
                int right = dp[i][j+1] ;
                int diagonal = dp[i+1][j+1] ;
                int down = dp[i+1][j] ;

                if(mat[i][j] == '1'){
                    dp[i][j] = 1 + min({right , down , diagonal}) ;
                    maxi = max(maxi , dp[i][j]) ;
                }
                else
                    dp[i][j] =  0 ;
            }
        }
        return maxi * maxi;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
         int maxi = 0 ;
        // solve(matrix , 0 , 0 , maxi ) ;

        vector<vector<int>> dp(n, vector<int>(m, -1));
   
        //  solveMem(matrix, 0, 0, maxi, dp);
        // return maxi * maxi; // Return area

        return solveTab(matrix) ;
    }
};
