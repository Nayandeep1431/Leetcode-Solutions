class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n = s.length() ; 
        int close = 0 ; 
        for(char ch : s){
            if(ch == ')')
                close++ ; 
        }
        int open = 0 ; 
        for(int i =0 ; i< n ; i++){
            if(s[i] == '(')
                open++ ;
            else
                close-- ; 
            
            if(open == close)
                return i+1 ; 
        }
        return (open == 0) ? n : 0 ;
    }
};
