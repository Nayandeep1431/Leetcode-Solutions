class Solution {
    long long solve(int ind ,vector<vector<int>>& questions ){
        if(ind >= questions.size())
            return 0 ;

        long long pick = questions[ind][0] + solve(ind + questions[ind][1]+1 , questions) ;
        long long notpick = solve(ind+1 , questions) ;
        return max(pick , notpick) ;  
    }
public:
long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            long long notpick = dp[i + 1];
            long long pick = questions[i][0];
            
            if (i + questions[i][1] + 1 < n) {
                pick += dp[i + questions[i][1] + 1];
            }
            
            dp[i] = max(pick, notpick);
        }
        
        return dp[0];
    }
};
