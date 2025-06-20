class Solution {
public:
    int solve(int ind , int l1 , int l2 , vector<int>&rods){
        if(ind >= rods.size()){
            if(l1 == l2)
                return l1 ;

            return 0 ;    
        }
        int addl1 = solve(ind+1 , l1+ rods[ind] , l2 , rods) ;
        int addl2 = solve(ind+1 , l1 , l2 + rods[ind] , rods) ;
        int nothing = solve(ind+1 , l1 , l2 , rods) ;
        return max({addl1 ,addl2 ,nothing}) ;
    }

    // Memoization
    int solveMem(int ind , int diff , vector<int>&rods , vector<vector<int>> &dp){
        if(ind >= rods.size()){
            if(diff == 0)
                return 0 ;

            return -1e9 ;    
        }

        if(dp[ind][diff+5000] != -1)
            return dp[ind][diff+5000];

        int addl1 = rods[ind] + solveMem(ind+1 , diff + rods[ind] , rods , dp) ;
        int addl2 = rods[ind] + solveMem(ind+1 , diff - rods[ind] , rods , dp) ;
        int nothing = solveMem(ind+1 ,diff , rods , dp) ;
        return dp[ind][diff+5000] = max({addl1 ,addl2 ,nothing}) ;
    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size() ;
        // return solve(0 ,0 , 0 , rods) ;

        vector<vector<int>> dp(n , vector<int> (10003 , -1)) ;
        return solveMem(0 ,0  , rods , dp) / 2  ;
    }
};
