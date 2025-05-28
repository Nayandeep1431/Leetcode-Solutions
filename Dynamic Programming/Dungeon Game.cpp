class Solution {
    // Recursion
int solve(int i , int j , vector<vector<int>> &mat){
    if(i == mat.size() - 1 && j == mat[0].size() - 1){
        return (mat[i][j] <= 0) ? abs(mat[i][j]) +1 : 1 ;
    }
    if(i >= mat.size() || j >= mat[0].size())
        return 1e9 ;
    
    int  right = solve(i , j+1 , mat) ;
    int bottom = solve(i+1 , j , mat) ;
    
    int result = min(right , bottom) - mat[i][j] ;
    return (result > 0) ? result : 1 ;
}

// Memoization
int solveMem(int i , int j , vector<vector<int>> &mat , vector<vector<int>> &dp){
    if(i == mat.size() - 1 && j == mat[0].size() - 1){
        return (mat[i][j] <= 0) ? abs(mat[i][j]) +1 : 1 ;
    }
    if(i >= mat.size() || j >= mat[0].size())
        return 1e9 ;
    if(dp[i][j] != -1)
        return dp[i][j] ;
    int  right = solveMem(i , j+1 , mat , dp) ;
    int bottom = solveMem(i+1 , j , mat ,dp) ;
    
    int result = min(right , bottom) - mat[i][j] ;
    return  dp[i][j] = (result > 0) ? result : 1 ;
}

// Tabulation
int solveTab(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) {
                dp[i][j] = (mat[i][j] <= 0) ? abs(mat[i][j]) + 1 : 1;
            } else {
                int right = (j + 1 < m) ? dp[i][j + 1] : INT_MAX;
                int down = (i + 1 < n) ? dp[i + 1][j] : INT_MAX;

                int needed = min(right, down) - mat[i][j];
                dp[i][j] = (needed > 0) ? needed : 1;
            }
        }
    }

    return dp[0][0];
}


public:
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;
        // return solve(0 , 0 , mat) ;

        // Memoization
        vector<vector<int>> dp(n , vector<int> (m , -1)) ;
        // return solveMem(0 , 0 , mat ,dp) ;

        return solveTab(mat) ;
    }
};
