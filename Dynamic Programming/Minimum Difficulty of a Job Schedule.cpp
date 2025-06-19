class Solution {
    int maxx(vector<int> &arr ,int ind , int n){
        int maxi = INT_MIN ;
        for(int i = ind ; i< n ; i++){
            maxi = max(maxi , arr[i]) ;
        }
        return maxi ;
    }
    int solve(vector<int> &arr , int days , int ind , int n , vector<vector<int>> &dp){
        if(days == 1){
            return maxx(arr ,ind , n ) ;
        }

        if(dp[ind][days] != -1)
            return dp[ind][days] ;

        int maxi = arr[ind] ;
        int finalres = INT_MAX ;
        for(int i = ind ; i<= n-days ; i++){
            maxi = max(maxi , arr[i]) ;
           int res = maxi + solve(arr, days-1 , i+1 , n , dp) ;
            finalres = min(finalres , res) ;
        }
        return dp[ind][days] = finalres ;
    }

int solveTab(vector<int> &arr, int days) {
    int n = arr.size();
    if (n < days) return -1;

    vector<vector<int>> dp(n + 1, vector<int>(days + 1, INT_MAX));

    // Base case: only 1 day left, take max of the suffix
    dp[n][1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i][1] = max(arr[i], dp[i + 1][1]);
    }

    for (int d = 2; d <= days; ++d) {
        for (int i = 0; i <= n - d; ++i) {
            int maxJob = 0;
            for (int j = i; j <= n - d; ++j) {
                maxJob = max(maxJob, arr[j]);
                if (dp[j + 1][d - 1] != INT_MAX)
                    dp[i][d] = min(dp[i][d], maxJob + dp[j + 1][d - 1]);
            }
        }
    }

    return dp[0][days];
}

public:
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size() ;
        if(n < d)
            return -1 ;

        if(n == d){
            int sum = accumulate(arr.begin() , arr.end() ,0) ;
            return sum ;
        }    

        // return solve(arr , d , 0 , n) ;
        vector<vector<int>> dp(n , vector<int> (d+1 , -1)) ;
        // return solve(arr , d , 0 , n , dp) ;

        return solveTab(arr ,d) ;
    }
};
