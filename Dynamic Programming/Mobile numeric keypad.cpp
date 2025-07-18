class Solution {
  public:
         vector<vector<int>>moves = {
            {0,8} , {1,2 , 4} , { 2,1,3,5} , { 3,2,6},{4,1,5,7} ,{5,2,4,6,8},{6,5,3,9},{7,4,8},{8,5,7,0,9},{9,8,6}
        };
    long long dfs(int i , int n , long long &cnt ,vector<vector<long long>>&dp){
        
        if( n == 1) {
            return 1;
        }
        
        if(dp[i][n] != -1){
            return dp[i][n];
        }
        
        long long ans= 0;
        for(auto neigh : moves[i]){
           ans+= dfs(neigh , n-1,cnt,dp);
        }
       return  dp[i][n] = ans;
        
    }
    
    long long getCount(int n) {
    
        long long cnt = 0 ;
        
        if(n == 1) return 10;
         
        vector<vector<long long>>dp(10 , vector<long long>(n+1 , -1));
        
        for(int i = 0 ; i < 10 ; i++){
           cnt += dfs(i,n, cnt,dp);
        }
        
        return cnt;
        
    }
};
