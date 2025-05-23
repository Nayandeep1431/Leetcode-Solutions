// User function Template for C++

class Solution {
  public:
  // Recursion
  int solve(vector<vector<int>> & mat , int i , int j , int &maxi){
      if(i >= mat.size() || j >= mat[0].size())
        return 0 ;
    
    int right = solve(mat , i , j+1 , maxi) ;
    int bottom = solve(mat , i +1,j ,maxi) ;
    int diagonal = solve(mat, i+1 , j+1 , maxi) ;
    
    if(mat[i][j] == 1){
        int ans = 1+ min({right , bottom , diagonal}) ;
        maxi = max(maxi , ans) ;
        return ans ;
    }   
    else
        return 0 ;
  }
  
  // Memoization
    int solveMem(vector<vector<int>> & mat , int i , int j , int &maxi , vector<vector<int>> &dp){
      if(i >= mat.size() || j >= mat[0].size())
        return 0 ;
    if(dp[i][j] != -1)
        return dp[i][j] ;
        
    int right = solveMem(mat , i , j+1 , maxi , dp) ;
    int bottom = solveMem(mat , i +1,j ,maxi , dp) ;
    int diagonal = solveMem(mat, i+1 , j+1 , maxi , dp) ;
    
    if(mat[i][j] == 1){
        int ans = 1+ min({right , bottom , diagonal}) ;
        maxi = max(maxi , ans) ;
        return dp[i][j] = ans ;
    }   
    else
        return dp[i][j] = 0 ;
  }
  
  // Tabulation
int solveTab(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxi = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int right = dp[i][j + 1];
            int bottom = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];

            if (mat[i][j] == 1) {
                int ans = 1 + min({right, bottom, diagonal});
                dp[i][j] = ans;
                maxi = max(maxi, ans);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

  
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int maxi = 0 ;
        int n = mat.size() ;
        int m = mat[0].size() ;
        vector<vector<int>> dp(n , vector<int> (m , -1)) ;
        // solve(mat , 0 , 0 , maxi) ;
        //  solveMem(mat , 0 , 0 , maxi , dp) ;
        // return maxi ;
        return solveTab(mat) ;
    }
};
