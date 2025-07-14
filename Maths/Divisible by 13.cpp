class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int n = s.size() ;
        int rem = 0 ;
        for(int i =0 ; i< n ; i++){
            int val = s[i] - '0' ;
            if(rem * 10 + val < 13){
                rem = rem * 10 + val;
            }
            else{
                int num = rem * 10 + val ;
                rem = num % 13 ;
            }    
        }
        return rem == 0 ;
    }
};
