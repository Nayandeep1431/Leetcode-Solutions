class Solution {
public:
    int solve(string s , char ch , int k){
        int l =0 , r = 0 , n = s.length() , maxi =0 , cnt= 0 ;

        while(r < n){
            char c = s[r] ;
            if(c != ch)
                cnt++ ;
            while(cnt > k){
                if(s[l] != ch)
                    cnt-- ;
                l++ ;    
            }    
            maxi = max(maxi , r-l+1) ;
            r++ ;
        }
        return maxi ;
    }
    int characterReplacement(string s, int k) {
        int n = s.length() ;
        int maxi =0 ;
        for(char ch = 'A' ; ch <= 'Z' ; ch++){
            int val = solve(s, ch , k) ;
            maxi = max(maxi ,val) ;
        }
        return maxi ;
    }
};
