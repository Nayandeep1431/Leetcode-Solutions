class Solution {
    typedef long long ll ;
public:
    unordered_map<string , int> mpp ; 
    bool isValid(string temp , int k){
        if(temp.size() == 0)
            return true ;
        int ans = 0 ;
        int n = temp.length() ;
        for(int i = n-1 ; i>=0 ; i--){
            int ch = temp[i] - '0' ;
            ans += ch * pow(2 , n-i-1) ;

            if(ans > k)
                return false ;
        }
        return true ;
    }

    int solve(string &s , int k ,int ind , string temp){
        if(!isValid(temp , k))
            return INT_MIN ;

        if(ind >= s.length())
            return temp.length() ;

        string key = to_string(ind) + "_" + temp ;
        if(mpp.count(key))
            return mpp[key] ;

        int take = solve(s , k , ind+1 , temp + s[ind]) ;
        int notTake = solve(s , k , ind+1 , temp) ;

        return mpp[key]= max(take , notTake) ;         
    }
    int longestSubsequence(string s, int k) {
        // string temp = "" ;
        // return solve(s , k , 0 , temp) ;
        int n = s.length() ;
        ll powerValue = 1;
        int len = 0 ;

        for(int i = n-1 ; i>=0 ; i--){
            if(s[i] == '0')
                len++ ;
            else if(powerValue <= k){
                k -= powerValue ;
                len++ ;
            }    
            if(powerValue <= k)
                powerValue <<= 1 ;
        }
        return len ;
    }
};
