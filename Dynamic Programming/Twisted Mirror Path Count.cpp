class Solution {
public:
    int mod = 1e9 + 7 ;
    int solve(int i , int j, int n , int m , vector<vector<int>> &grid , bool r){
        if(i == n-1 && j == m-1)
            return 1 ;

        if(i >= n || i < 0 || j < 0 || j >= m )
            return 0 ;

        int right = 0 , down = 0 ;    
        if(grid[i][j] == 1){
            if(r)
                right = solve(i+1 , j , n , m ,grid , false) ;
            else
                down = solve(i , j+1 ,n , m , grid , true ) ;    
        } 

        else{
        down = solve(i+1 , j , n , m , grid , false) ;
         right = solve(i , j+1 , n , m ,grid ,  true) ;
        }
       
        return (right + down) % mod ;
    }

    int solveMem(int i , int j, int n , int m , vector<vector<int>> &grid , int r , vector<vector<vector<int>>>&dp){
        if(i == n-1 && j == m-1)
            return 1 ;

        if(i >= n || i < 0 || j < 0 || j >= m )
            return 0 ;
        if(dp[i][j][r] != -1)
            return dp[i][j][r] ;

        int right = 0 , down = 0 ;    
        if(grid[i][j] == 1){
            if(r)
                right = solveMem(i+1 , j , n , m ,grid , 0 , dp) ;
            else
                down = solveMem(i , j+1 ,n , m , grid , 1 , dp ) ;    
        } 

        else{
        down = solveMem(i+1 , j , n , m , grid , 0 , dp) ;
         right = solveMem(i , j+1 , n , m ,grid ,  1 , dp) ;
        }
       
        return dp[i][j][r] = (right + down) % mod ;
    }

    // Tabulation
int solveTab(vector<vector<int>> &grid, int n, int m) {
    const int mod = 1000000007;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, 0)));
    dp[n-1][m-1][0] = 1;
    dp[n-1][m-1][1] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            for (int k = 0; k <= 1; k++) {
                if (i == n-1 && j == m-1) continue;
                int right = 0, down = 0;
                if (grid[i][j] == 1) {
                    if (k == 1 && i + 1 < n)
                        right = dp[i+1][j][0];
                    else if (k == 0 && j + 1 < m)
                        down = dp[i][j+1][1];
                } else {
                    if (i + 1 < n)
                        down = dp[i+1][j][0];
                    if (j + 1 < m)
                        right = dp[i][j+1][1];
                }
                dp[i][j][k] = (right + down) % mod;
            }
        }
    }
    return dp[0][0][0];
}

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int right = false ;
        // return solve(0 , 0 , n , m , grid , right) ;

        vector<vector<vector<int>>> dp(n , vector<vector<int>> (m , vector<int>(2 ,-1))) ;
        // return solveMem(0 , 0 , n , m , grid , right , dp) ;
        return solveTab(grid , n , m) ;
    }
};
