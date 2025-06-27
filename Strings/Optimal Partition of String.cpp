class Solution {
public:
    int partitionString(string s) {
        unordered_map<char , int> mpp ;
        int n = s.length() ;
        int cnt =1 ;
        for(int i =0 ; i< n ; i++){
            char ch = s[i] ;
            if(mpp.find(ch) != mpp.end()){
                mpp.clear() ;
                cnt++ ;
                mpp[ch]++ ;
            }
            else
                mpp[ch]++ ;
        }
        return cnt ;
    }
};
