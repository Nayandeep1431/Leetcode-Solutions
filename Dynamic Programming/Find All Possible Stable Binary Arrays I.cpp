class Solution {
public:
    int mod = 1e9 + 7 ;
    static const int MAX = 201;
    int dp[MAX][MAX][3][MAX];

    int solve(int zero , int one , int prev , int cnt , int limit){
        if(zero == 0 && one == 0)
            return 1 ;

        int ans = 0 ; 
        if(cnt == limit){
            if(prev == 0 && one > 0)
                ans += solve(zero , one-1 , 1 , 1 , limit) ; 
            else if(prev == 1  && zero >  0)
                ans += solve(zero -1 , one , 0 , 1 , limit) ;
            else
                return 0 ;        
        }   
        else{
        if(one > 0){
            if(prev == 1)
                ans += solve(zero , one-1 , 1 , cnt+1 ,limit) % mod ;
            else
                ans += solve(zero , one-1 , 1 , 1 , limit) % mod ;      
        }
           
        if(zero > 0){
            if(prev == 0)
                ans += solve(zero-1 , one , 0 , cnt+1 ,limit) % mod ;
            else
                ans += solve(zero-1 , one , 0 , 1 , limit) % mod ;      
        }
        }        
        return ans % mod;
    }

    int solveMem(int zero, int one, int prev, int cnt, int limit) {
        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][prev][cnt] != -1)
            return dp[zero][one][prev][cnt];

        int ans = 0;

        if (cnt == limit) {
            if (prev == 0 && one > 0)
                ans = solveMem(zero, one - 1, 1, 1, limit);
            else if (prev == 1 && zero > 0)
                ans = solveMem(zero - 1, one, 0, 1, limit);
            else
                return 0;
        } else {
            if (one > 0) {
                if (prev == 1)
                    ans = (ans + solveMem(zero, one - 1, 1, cnt + 1, limit)) % mod;
                else
                    ans = (ans + solveMem(zero, one - 1, 1, 1, limit)) % mod;
            }

            if (zero > 0) {
                if (prev == 0)
                    ans = (ans + solveMem(zero - 1, one, 0, cnt + 1, limit)) % mod;
                else
                    ans = (ans + solveMem(zero - 1, one, 0, 1, limit)) % mod;
            }
        }

        return dp[zero][one][prev][cnt] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        // return solve(zero , one , -1 , 0 , limit) ; 

        // memset(dp, -1, sizeof(dp));
        // return solveMem(zero, one, 2, 0, limit);
       vector<vector<vector<vector<int>>>> dp(
        zero + 1,
        vector<vector<vector<int>>>(
            one + 1,
            vector<vector<int>>(3, vector<int>(limit + 1, 0))
        )
    );

    for (int prev = 0; prev < 3; prev++)
        for (int cnt = 0; cnt <= limit; cnt++)
            dp[0][0][prev][cnt] = 1;

    for (int z = 0; z <= zero; z++) {
        for (int o = 0; o <= one; o++) {

            if (z == 0 && o == 0)
                continue;

            for (int prev = 0; prev < 3; prev++) {

                for (int cnt = 0; cnt <= limit; cnt++) {

                    long long ans = 0;

                    if (cnt == limit) {

                        if (prev == 0 && o > 0)
                            ans = dp[z][o - 1][1][1];

                        else if (prev == 1 && z > 0)
                            ans = dp[z - 1][o][0][1];

                        else
                            ans = 0;

                    } else {

                        if (o > 0) {
                            if (prev == 1)
                                ans = (ans + dp[z][o - 1][1][cnt + 1]) % mod;
                            else
                                ans = (ans + dp[z][o - 1][1][1]) % mod ;
                        }

                        if (z > 0) {
                            if (prev == 0)
                                ans = (ans + dp[z - 1][o][0][cnt + 1]) % mod ;
                            else
                                ans = (ans + dp[z - 1][o][0][1]) % mod ;
                        }
                    }

                    dp[z][o][prev][cnt] = ans % mod ;
                }
            }
        }
    }

    return dp[zero][one][2][0];
}
    
};
