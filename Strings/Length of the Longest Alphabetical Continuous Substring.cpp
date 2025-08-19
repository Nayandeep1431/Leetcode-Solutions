class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length() ;
        int maxi = 1 ;
        int cnt = 1 ;
        int prev = s[0] - 'a' ;
        for(int i =1 ; i< n ; i++){
            int ch = s[i] - 'a' ;
            if(ch == prev +1){
                cnt++ ;
            }
            else
                cnt = 1 ;

            prev = ch ;
            maxi = max(maxi , cnt) ;    
        }
        return maxi ;
    }
};
