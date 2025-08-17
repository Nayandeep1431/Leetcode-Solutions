class Solution {
public:
    typedef long long ll ;
    ll solve(int ind , int k , int state , vector<int>&arr , vector<vector<vector<ll>>> &dp ){
        if(ind == arr.size()){
            if(k >= 0 && state == 0)
                return 0 ;
            else
                return INT_MIN ;    
        }

        if(dp[ind][k][state] != -1)
            return dp[ind][k][state] ;

        ll profit = 0 ;
        if(k > 0){
            if(state == 0)
                profit = max(-arr[ind] + solve(ind +1 , k , 1 ,arr,dp) , arr[ind] + solve(ind+1 , k , 2 , arr, dp)) ;
            else if(state ==1 )
                profit =  arr[ind] + solve(ind+1 ,k-1 , 0 , arr, dp ) ;
            else if(state ==2 )
                profit = -arr[ind] + solve(ind+1 , k-1 , 0 ,arr , dp) ;        
        }   
        ll np = solve(ind+1 , k , state ,arr , dp)  ;
        return dp[ind][k][state] = max(profit , np) ;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size() ;
        vector<vector<vector<ll>>> dp(n , vector<vector<ll>> (k+1 , vector<ll> (3 , -1))) ;

        return solve(0 ,k , 0 , prices , dp) ;
    }
};
