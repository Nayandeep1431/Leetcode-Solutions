class Solution {
  public:

// Recursion
    int solve(int n , int sum){
        if(n == 0 && sum == 0)
            return 1 ; 
        
        if(sum < 0)
            return 0 ;
        
        if(n <= 0)
            return 0 ;
        
        int cnt = 0 ;
        for(int i = 0 ; i<= 9 ; i++){
            if(i <= sum)
                cnt += solve(n-1 , sum - i) ;
        }
        return cnt ;
    }

//Memoization
int solveMem(int n, int sum, vector<vector<int>> &dp) {
    if (sum < 0)
        return 0;

    if (n == 0)
        return (sum == 0);

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int cnt = 0;

    for (int i = 0; i <= 9; i++) {
        cnt += solveMem(n - 1, sum - i, dp);
    }

    return dp[n][sum] = cnt;
}

int countWays(int n, int sum) {
    if (sum == 0)
        return (n == 1) ? 1 : -1;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    int cnt = 0;

    // First digit cannot be 0
    for (int first = 1; first <= 9; first++) {
        if (first <= sum)
            cnt += solveMem(n - 1, sum - first, dp);
    }

    return (cnt == 0) ? -1 : cnt;
}
};
