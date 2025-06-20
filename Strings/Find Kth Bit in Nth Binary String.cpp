class Solution {
public:
    string invRev(string s){
        for(int i =0 ; i< s.length() ; i++){
            if(s[i] == '0')
                s[i] = '1' ;
            else
                s[i] = '0' ;   
        }
        reverse(s.begin() , s.end()) ;
        return s ;
    }
    char findKthBit(int n, int k) {
        string s = "0" ;
        for(int i =2 ; i<= n ; i++){
            s = s + "1" + invRev(s) ;
        }
        return s[k-1] ;
    }
};
