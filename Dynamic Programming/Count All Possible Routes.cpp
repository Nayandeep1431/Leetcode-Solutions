class Solution {
    int mod = 1e9+7 ;
    int solve(vector<int> &arr , int start , int dest , int fuel ){
        if(fuel < 0)
            return 0 ;
        
        int ans = 0 ;
        if(start == dest)
            ans += 1 ;

        for(int i = 0 ; i< arr.size() ; i++){
            if(i != start){
                int rem = fuel - abs(arr[start] - arr[i]) ;
                ans = (ans + solve(arr , i , dest , rem))  % mod;
            }
        }
        return ans ;
    }

//Memoization
    int solveMem(vector<int> &arr , int start , int dest , int fuel, vector<vector<int>> &dp){
        if(fuel < 0)
            return 0 ;

        if(dp[start][fuel] != -1)
            return dp[start][fuel] ;
        int ans = 0 ;
        if(start == dest)
            ans += 1 ;

        for(int i = 0 ; i< arr.size() ; i++){
            if(i != start){
                int rem = fuel - abs(arr[start] - arr[i]) ;
                ans = (ans + solveMem(arr , i , dest , rem , dp))  % mod;
            }
        }
        return  dp[start][fuel] = ans ;
    }

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       int n = locations.size() ;
    //    return solve(locations , start , finish , fuel) ;

       vector<vector<int>> dp(n , vector<int> (fuel+1 , -1)) ;
       return solveMem(locations , start , finish , fuel ,dp) ;
    }
};
