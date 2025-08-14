class Solution {
public:
    //  Memoization
    int solve(int ind  , int t , vector<int> &arr , vector<int> &dp){
        if(ind == arr.size() -1)
            return 0 ;
        if(dp[ind] != -1)
            return dp[ind] ;
        int maxi = 0 ;
        for(int i = ind +1 ; i< arr.size() ; i++ ){
            int ele = arr[i] ;
            if(abs(arr[ind] - arr[i]) <= t)
                maxi = max(maxi , 1 + solve(i , t , arr ,dp)) ;
        }    
        return dp[ind] = (maxi == 0) ? -1 : maxi ;
    }

    // Tabulation
int solveTab(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;

        for (int ind = n - 2; ind >= 0; ind--) {
            int maxi = -1;
            for (int i = ind + 1; i < n; i++) {
                if (abs(1LL * nums[ind] - nums[i]) <= target && dp[i] != -1)
                    maxi = max(maxi, 1 + dp[i]);
            }
            dp[ind] = maxi;
        }
        return dp[0];
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size() ;
        vector<int> dp(n , -1) ;
        // int maxi = max(0 , solve(0, target , nums , dp)) ;

        // return (maxi == 0) ? -1 : maxi ;
        return solveTab(nums , target) ;
    }
};
