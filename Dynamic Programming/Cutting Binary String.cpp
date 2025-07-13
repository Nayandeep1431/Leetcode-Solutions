class Solution {
  public:
    bool isPowerOfFive(const string& numStr) 
    {
        if(numStr[0] == '0') return false; 
        
        long long num = stoll(numStr, nullptr, 2);
    
        while(num > 1) 
        {
            if(num % 5 != 0) return false;
            num /= 5;
        }
    
        return num == 1;
    }
    
    int solve(const string &s, int start, int n, vector<int>& dp) 
    {
        if(start == n) return 0;
        
        if(dp[start] != -1) return dp[start];
        
        int minCuts = INT_MAX;
        
        for(int i = start+1 ; i <= n ; i++)
        {
            string str = s.substr(start , i - start);
            
            if(isPowerOfFive(str))
            {
                int res = solve(s , i , n , dp);
                
                if(res != -1)
                {
                    minCuts = min(minCuts , 1 + res);
                }
            }
        }
        
        return dp[start] = (minCuts == INT_MAX) ? -1 : minCuts;
    }
    
    int cuts(string s){
        
        int n = s.size();
        
        vector<int> dp(n, -1);
        
        return solve(s, 0, n, dp);
        
    }
};
