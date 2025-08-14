class Solution {
public:
    string ans(int num){
        char ch = num + '0' ;
        string res = "" ;
        for(int i =0 ; i< 3 ; i++)
            res += ch ;

        return res ;    
    }
    string largestGoodInteger(string s) {
        int n = s.size() ;

        int maxi = INT_MIN ;
        int cnt = 0 ;
        int prev = -1 ;

        for(int i =0 ; i< n ; i++){
            int ch = s[i] - '0' ;
            if(ch == prev){  
                cnt++ ;

                if(cnt >= 3)
                    maxi = max(maxi , ch) ;
            }    
            else{
                cnt = 1 ;
            }
            prev = ch ;
        }
        if(maxi == INT_MIN)
            return "" ;
        else
            return ans(maxi) ;
          
    }
};
