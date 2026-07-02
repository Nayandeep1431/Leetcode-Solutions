class Solution {
public:
    int solve(vector<int> &cuts , int i , int j){
         if(i >j)
            return 0 ; 
        int mini = INT_MAX ;     
        for(int ind = i ; ind <= j ; ind++){
            int ans = cuts[j+1] - cuts[i-1] + solve(cuts , i , ind-1) + solve(cuts , ind+1 , j) ; 
            mini = min(mini , ans) ; 
        }    
        return mini ;
    }

    int solveMem(vector<int> &cuts , int i , int j ,vector<vector<int>> &dp){
         if(i >j)
            return 0 ; 
        if(dp[i][j] != -1)
            return dp[i][j] ;   

        int mini = INT_MAX ;     
        for(int ind = i ; ind <= j ; ind++){
            int ans = cuts[j+1] - cuts[i-1] + solveMem(cuts , i , ind-1 ,dp) + solveMem(cuts , ind+1 , j , dp) ; 
            mini = min(mini , ans) ; 
        }    
        return dp[i][j] = mini ;
    }

// Tabulation 
    int solveTab(vector<int> &cuts , int n , int c){
        vector<vector<int>> dp(c+2 , vector<int> (c+2 , 0)) ;
        for(int i = c ; i>= 1 ; i--){
            for(int j = i ; j<=c ; j++){
                int mini = INT_MAX ; 
                for(int ind = i ; ind <= j ; ind++){
                    int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j] ; 
                    mini= min(mini , ans) ; 
                }
                dp[i][j] = mini ;
            }
        }
        return dp[1][c] ;
    }

    int minCost(int n, vector<int>& cuts) {
        int i = 0, j = n ; 
        int c = cuts.size() ; 
        cuts.push_back(0)  ;
        cuts.push_back(n) ; 
        sort(cuts.begin() , cuts.end()) ;
        // return solve(cuts , 1 , c ) ; 
        
        vector<vector<int>> dp(c+1 , vector<int> (c+1 , -1)) ;
        // return solveMem(cuts , 1 , c , dp) ;  

        return solveTab(cuts , n , c) ; 
    }
};
