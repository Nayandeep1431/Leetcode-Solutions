class Solution {
    int solve(int ind , vector<int> cost , vector<int> &dp){
        if(ind ==0)
            return cost[0];

        if(ind == 1)
            return cost[1];
        if(dp[ind] != -1)
            return dp[ind] ;

        dp[ind] =  cost[ind] + min(solve(ind-1 , cost , dp) , solve(ind-2 , cost , dp));  
        return dp[ind] ;      
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> dp(n , -1) ;
        // return min(solve(n-1 , cost , dp) , solve(n-2 ,cost , dp));
        dp[0] = cost[0];
        dp[1] = cost[1] ;
        for(int i =2 ; i< n ; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1] ,dp[n-2]);
    }
};
