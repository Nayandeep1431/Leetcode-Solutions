class Solution {
  public:
    int dp[13][13] ; 
    int solve(int ind , int n , int m , int prev ){
        if(ind > n)
            return 1 ; 
        if(dp[ind][prev] != -1)
            return dp[ind][prev] ; 
            
        int cnt = 0 ; 
        for(int i = 1; i<= m ; i++){
            if((prev % i == 0) ||(i % prev == 0))
                cnt += solve(ind+1 , n , m , i) ; 
        }
        return dp[ind][prev] = cnt ;
    }
    int count(int n, int m) {
        // code here
        memset(dp , -1 , sizeof(dp)) ;
        int cnt = 0 ; 
        for(int i = 1 ; i<= m ; i++){
            cnt += solve(2 , n ,m , i) ;
        }
        return cnt ; 
    }
}; 
