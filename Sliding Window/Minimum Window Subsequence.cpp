class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.length() ; 
        int m = s2.length() ; 
        vector<vector<int>> dp(n , vector<int> (m , -1)) ; 
        for(int i =0 ; i< n ; i++){
            if(s1[i] == s2[0])
                dp[i][0] = i ; 
            else if(i)
                dp[i][0] = dp[i-1][0] ; 
        }
        
        for(int j = 1 ; j< m ; j++){
            for(int i = 1 ; i< n ; i++){
                if(s2[j] == s1[i])
                    dp[i][j] = dp[i-1][j-1] ;
                else
                    dp[i][j] = dp[i-1][j] ;
            }
        }
        int len = INT_MAX ; 
        int start = -1 ; 
        for(int i = 0 ; i < n; i++){
            if(dp[i][m-1] != -1){
                int curr = i - dp[i][m-1] + 1 ; 
                if(curr < len){
                    len = curr ; 
                    start = dp[i][m-1] ; 
                }
            }
        }
        if(start == -1)
            return "" ; 
        
        return s1.substr(start ,len) ;     
    }
};
