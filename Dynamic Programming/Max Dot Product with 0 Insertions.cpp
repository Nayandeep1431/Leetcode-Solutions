class Solution {
  public:

    // Recursion
    int solve(vector<int> &a , int ind1 , vector<int> &b , int ind2 ){
        if(ind2 < 0)
            return 0 ;
        if(ind1 < 0 && ind2 >=0)
            return INT_MIN ;
            
        int notTake = solve(a, ind1-1 , b , ind2) ; 
        int take =  a[ind1] * b[ind2] + solve(a , ind1-1 , b , ind2-1 ) ; 
            
        return max(notTake , take) ;     
    }
    
    // Memoization 
    int solveMem(vector<int> &a , int ind1 , vector<int> &b , int ind2 , vector<vector<int>> &dp){

        if(ind2 < 0)
            return 0 ;
        if(ind1 < 0 && ind2 >= 0)
            return INT_MIN ;
            
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2] ;
            
        int notTake = solveMem(a, ind1-1 , b , ind2 , dp) ; 
        int take = a[ind1] * b[ind2] + solveMem(a , ind1-1 , b , ind2-1 , dp) ; 
            
        return dp[ind1][ind2] = max(notTake , take) ;     
    }    
    
    // Tabulation 
  int solveTab(vector<int>& a,vector<int>& b){
        int n=b.size();
        int m=a.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MIN));
        for(int i=0;i<=m;i++){
            dp[i][n]=0;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int take=a[i]*b[j] + dp[i+1][j+1];
                int notTake= a[i]*0 + dp[i+1][j];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
    
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size() ; 
        int m = b.size() ;
        int diff = n - m ; 
        // return solve(a , n-1 , b , m-1 ) ; 
        
        vector<vector<int>> dp(n , vector<int>(m , -1)) ;
        return solveMem(a ,n-1 , b , m-1 , dp ) ;
    }
};
