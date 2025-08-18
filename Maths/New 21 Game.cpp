class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1);
        dp[0] = 1;
        double curr = (k == 0) ? 0 : 1 ;
        for(int i = 1; i<= n ; i++){
            dp[i] = curr / maxPts ;

            if(i < k)
                curr += dp[i] ;

            if(i - maxPts >= 0 && i - maxPts < k)
                curr -= dp[i - maxPts] ;    
        }
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};
