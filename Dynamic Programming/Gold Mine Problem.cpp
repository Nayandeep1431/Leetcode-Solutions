class Solution {
  public:
    // Recursion
    int solve(int i , int j , vector<vector<int>> &mat){
        if(j >= mat[0].size())
            return 0 ;
        
        int right = mat[i][j] + solve(i , j+1 , mat) ;
        int rightBottom = mat[i][j] ;
        if(i+1 < mat.size())
            rightBottom += solve(i+1 , j+1 , mat) ;
        
        int leftBottom = mat[i][j] ;
        if(i-1 >= 0)
            leftBottom += solve(i-1 , j+1 , mat) ;
        
        return max({right , rightBottom , leftBottom}) ;    
    }
    
    // Memoization
    int solveMem(int i , int j , vector<vector<int>> &mat ,vector<vector<int>> &dp){
        if(j >= mat[0].size())
            return 0 ;
        
        if(dp[i][j] != -1)
            return dp[i][j] ;
            
        int right = mat[i][j] + solveMem(i , j+1 , mat ,dp) ;
        int rightBottom = mat[i][j] ;
        if(i+1 < mat.size())
            rightBottom += solveMem(i+1 , j+1 , mat ,dp) ;
        
        int leftBottom = mat[i][j] ;
        if(i-1 >= 0)
            leftBottom += solveMem(i-1 , j+1 , mat , dp) ;
        
        return dp[i][j] = max({right , rightBottom , leftBottom}) ;    
    }
    
    // Tabulation
    int solveTab(vector<vector<int>> &mat){
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));
    
        for (int j = col - 1; j >= 0; j--) {
            for (int i = 0; i < row; i++) {
                 int right = (j + 1 < col) ? dp[i][j + 1] : 0;
                int rightUp = (i - 1 >= 0 && j + 1 < col) ? dp[i - 1][j + 1] : 0;
                int rightDown = (i + 1 < row && j + 1 < col) ? dp[i + 1][j + 1] : 0;

            dp[i][j] = mat[i][j] + max({right, rightUp, rightDown});
        }
    }

       int ans = 0;
        for (int i = 0; i < row; i++) {
            ans = max(ans, dp[i][0]);
        }

        return ans;
        }
    
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int row = mat.size() ;
        int col = mat[0].size() ;
        
        // vector<vector<int>> dp(row , vector<int> (col , -1)) ;
        // int ans = INT_MIN ;
        // for(int i =0 ; i< row ; i++){
        //     ans = max(ans , solveMem(i , 0 , mat , dp)) ;
        // }
        return solveTab(mat) ;
    }
};
