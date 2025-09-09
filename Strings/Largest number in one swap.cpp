class Solution {
  public:

    string largestSwap(string &s) {
        vector<int> last(10 , -1) ;
        int n = s.length() ;
        for(int i =0 ; i< n ; i++){
            int curr = s[i] - '0' ;
            last[curr] = i ;
        }
        for(int i =0 ; i< n ; i++){
            int curr = s[i] - '0' ;
            for(int j = 9 ; j> curr ; j--){
                if(last[j] > i){
                    swap(s[i] , s[last[j]]) ;
                    return s ;
                }
            }
        }
        return s ;
    }
};
