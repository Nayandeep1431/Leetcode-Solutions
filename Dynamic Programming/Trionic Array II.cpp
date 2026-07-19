class Solution {
public:
    typedef long long ll ;
    int n ; 
    ll solve(vector<int> &nums , int ind , int trend){
        if(ind == n){
            if(trend == 3)
                return 0 ;
            else
                return LLONG_MIN ;    
        }
        ll take = LLONG_MIN/2 ;
        ll skip = LLONG_MIN/2 ;

        if(trend == 0)
            skip = solve(nums , ind+1 , trend) ; 

        if(trend == 3)
            take = nums[ind] ;     

        if(ind + 1 < n){
            int curr = nums[ind] ;
            int next = nums[ind+1] ; 
            if(trend == 0 && next > curr)
                take = max(take , curr + solve(nums , ind+1 , 1)) ; 
            else if(trend == 1){
                if(next > curr)
                    take = max(take , curr+ solve(nums , ind+1 , 1)) ; 
                else if(next < curr)
                    take = max(take , curr + solve(nums , ind+1 , 2))  ;    
            }    
            else if(trend == 2){
                if(next < curr)
                    take = max(take , curr + solve(nums , ind+1 , 2)) ;
                else if(next > curr)
                    take = max(take , curr + solve(nums , ind+1 , 3)) ;     
            }
            else if(trend == 3 && next > curr)
                take = max(take , curr + solve(nums , ind+1 , 3)) ; 
        }    
        return max(take , skip) ; 
    }

    ll solveMem(vector<int> &nums , int ind , int trend ,vector<vector<ll>> &dp){
        if(ind == n){
            if(trend == 3)
                return 0 ;
            else
                return LLONG_MIN/2 ;    
        }

        if(dp[ind][trend] != LLONG_MIN)
            return dp[ind][trend] ;

        ll take = LLONG_MIN/2 ;
        ll skip = LLONG_MIN/2 ;

        if(trend == 0)
            skip = solveMem(nums , ind+1 , trend , dp) ; 

        if(trend == 3)
            take = nums[ind] ;     

        if(ind + 1 < n){
            int curr = nums[ind] ;
            int next = nums[ind+1] ; 

            if(trend == 0 && next > curr)
                take = max(take , curr + solveMem(nums , ind+1 , 1,dp)) ; 
            else if(trend == 1){
                if(next > curr)
                    take = max(take , curr+ solveMem(nums , ind+1 , 1 ,dp)) ; 
                else if(next < curr)
                    take = max(take , curr + solveMem(nums , ind+1 , 2 , dp))  ;    
            }    
            else if(trend == 2){
                if(next < curr)
                    take = max(take , curr + solveMem(nums , ind+1 , 2 , dp)) ;
                else if(next > curr)
                    take = max(take , curr + solveMem(nums , ind+1 , 3 , dp)) ;     
            }
            else if(trend == 3 && next > curr)
                take = max(take , curr + solveMem(nums , ind+1 , 3 , dp)) ; 
        }    
        return dp[ind][trend]  = max(take , skip) ; 
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size() ; 
        // return solve(nums , 0 , 0) ; 

        vector<vector<ll>> dp(n+1 , vector<ll> (4 , LLONG_MIN)) ;
        return solveMem(nums , 0 , 0 , dp) ;
    }
};
