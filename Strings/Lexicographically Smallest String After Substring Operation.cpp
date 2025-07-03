class Solution {
public:
    string solve(string s , int start , int end){
        for(int i = start ; i<= end ; i++){
            s[i] = s[i] - 1 ;
        }
        return s ;
    }
    string smallestString(string s) {
       int start = -1 , end = -1 ;
       for(int i =0 ; i< s.length() ; i++){
            char ch = s[i] ;
            if(ch != 'a'){
                if(start == -1)
                    start = i ;
                end = i ;    
            }
            else{
                if(start != -1)
                    break ;
            }
       }    
       if(start == -1){
            s[s.length() - 1] = 'z' ;
            return s;
       }
       return solve(s , start , end) ;
    }
};
