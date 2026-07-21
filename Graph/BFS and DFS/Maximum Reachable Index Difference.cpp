class Solution {
  public:
    void solve(vector<vector<int>> &dp , int ind , int prev , int &maxi){
        if(dp[ind].size() == 0)
            return ;
        
        for(int it : dp[ind]){
            if(it > prev){
                maxi = max(maxi , it) ; 
                solve(dp , ind+1 , it ,maxi) ; 
            }
        }    
    }
    int maxIndexDifference(string &s) {
        // code here
        int n = s.length() ; 
        vector<vector<int>> dp(26) ; 
        for(int i =0 ; i< n ; i++){
            dp[s[i] - 'a'].push_back(i) ; 
        }
        if(dp[0].size() == 0)
            return - 1; 
        
        int maxi = -1;
        for(int i = 0 ; i < dp[0].size() ; i++){
            int ind = dp[0][i] ; 
            
            int val = ind ; 
            solve(dp , 1 ,ind ,  val) ; 
            maxi = max(maxi , val - ind ) ; 
        }
        return maxi ;
    }
};
