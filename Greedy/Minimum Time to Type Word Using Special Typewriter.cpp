class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size() ;
        int curr = 1 ;
        int cnt = n ;
        for(int i =0 ; i< n ; i++){
            int val = word[i] - 'a' + 1;
            int move = min({abs(curr - val) , abs(curr + 26 - val) , abs(curr - val - 26)}) ;
            cnt += move ;
            curr = val ;
        }
        return cnt ;
    }
};
