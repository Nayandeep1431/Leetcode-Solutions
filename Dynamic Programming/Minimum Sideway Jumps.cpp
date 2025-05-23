class Solution {
    //  Recurison
    int solve(vector<int> &arr , int currLane , int pos){
        if(pos == arr.size() -1)
            return 0 ;

        if(arr[pos+1] != currLane)
            return solve(arr , currLane , pos+1) ;
        else{
            int ans = INT_MAX ;
            for(int i = 1; i<= 3 ; i++){
                if(currLane != i && arr[pos] != i)
                    ans = min(ans , 1+ solve(arr , i , pos)) ;
            }
            return ans ;
        }         
    }

    // Memoization
    int solveMem(vector<int> &arr , int currLane , int pos , vector<vector<int>> &dp){
        if(pos == arr.size() -1)
            return 0 ;

        if(dp[currLane][pos] != -1)
            return dp[currLane][pos] ;

        if(arr[pos+1] != currLane)
            return solveMem(arr , currLane , pos+1 , dp) ;
        else{
            int ans = INT_MAX ;
            for(int i = 1; i<= 3 ; i++){
                if(currLane != i && arr[pos] != i)
                    ans = min(ans , 1+ solveMem(arr , i , pos ,dp)) ;
            }
            return dp[currLane][pos] = ans ;
        }         
    }

// Tabulation
int solveTab(vector<int> &obstacles){
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, 1e9));

    for (int i = 1; i <= 3; i++) {
        dp[i][n - 1] = 0;
    }

    for (int currPos = n - 2; currPos >= 0; currPos--) {
        for (int currLane = 1; currLane <= 3; currLane++) {
            if (obstacles[currPos + 1] != currLane) {
                dp[currLane][currPos] = dp[currLane][currPos + 1];
            } else {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++) {
                    if (currLane != i && obstacles[currPos] != i)
                        ans = min(ans, 1 + dp[i][currPos + 1]);
                }
                dp[currLane][currPos] = ans;
            }
        }
    }

    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}


public:
    int minSideJumps(vector<int>& obstacles) {
        // return solve(obstacles , 2 , 0) ; // Recursion
        int n = obstacles.size() ;
        // vector<vector<int>> dp(4 , vector<int>(n , -1)) ;
        // return solveMem(obstacles , 2 , 0 , dp) ; // Memoization

        return solveTab(obstacles ) ;
    }
};
