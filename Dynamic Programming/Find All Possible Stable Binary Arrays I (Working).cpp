class Solution {
public:
    int mod = 1e9 + 7 ;
    static const int MAX = 201;
    int dp[MAX][MAX][2];
     int t[MAX][MAX][2];

    int solveMem(int zero , int one , bool last , int limit){
        if(zero == 0 && one == 0)
            return 1 ; 

        if(dp[zero][one][last] != -1)   
            return dp[zero][one][last] ;

        int res = 0 ; 
        if(last){
            for(int i = 1 ; i<= min(zero , limit) ; i++)
                res = (res + solveMem(zero - i , one ,false , limit)) % mod ; 
        }   
        else{
            for(int i = 1; i<= min(one , limit) ; i++)
                res = (res + solveMem(zero , one - i , true , limit)) % mod ; 
        }   
        return dp[zero][one][last] = res % mod ; 
    }

   int solveTab(int zero, int one, int limit) {

        memset(t, 0, sizeof(t));

        t[0][0][0] = 1;
        t[0][0][1] = 1;


        for(int onesLeft = 0; onesLeft <= one; onesLeft++) {
            for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++) {

                if(onesLeft == 0 && zerosLeft == 0) continue;

                int result = 0;

                result = 0;
                for(int len = 1; len <= min(zerosLeft, limit); len++) {
                    result = (result + t[onesLeft][zerosLeft - len][0]) % mod;
                }
                t[onesLeft][zerosLeft][1] = result;

                result = 0;
                for(int len = 1; len <= min(onesLeft, limit); len++) {
                    result = (result + t[onesLeft - len][zerosLeft][1]) % mod;
                }
                t[onesLeft][zerosLeft][0] = result;
            }
        }

        int startWithOne  = t[one][zero][false]; 
        int startWithZero = t[one][zero][true]; 

        return (startWithOne + startWithZero) % mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        // return solve(zero , one , -1 , 0 , limit) ; 

        // memset(dp, -1, sizeof(dp));
        // int startOne = solveMem(zero , one , true , limit) % mod; 
        // int startZero = solveMem(zero , one , false , limit) % mod ; 

        // return (startOne + startZero ) % mod ; 

        return solveTab(zero , one , limit) ; 
    
}
    
};
