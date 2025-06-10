class Solution {
  public:
    int countStrings(string &s) {
         int n = s.length() ;
        vector<int> dp(n , 0) ;
        vector<int> val(26 , 0) ;
        bool same = false ;
       
        for(int i =n-1 ; i>=0 ; i-- ){
            int ch = s[i] - 'a' ;
            int cnt = n - i - 1 - val[ch] ;
            if(val[ch] != 0)
                same = true ;
            val[ch]++ ;
            dp[i] = cnt ;    
        }
        int ans = (same) ? 1 : 0 ;
        for(int i = 0 ; i< n ; i++ )
            ans += dp[i] ;
        
        return ans ;    
    }
};
