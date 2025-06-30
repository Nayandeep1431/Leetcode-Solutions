class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.length() ;
        int cnt = 0 ;
        unordered_map<char , int> mpp ;
        for(int i = 0 ; i< k ; i++){
            mpp[s[i]]++ ;
        }
        if(mpp.size() == k-1)
            cnt++ ;
        
        for(int i = k ; i < n ; i++){
            char prev = s[i-k] ;
            mpp[prev]-- ;
            if(mpp[prev] == 0)
                mpp.erase(prev) ;
            
            mpp[s[i]] ++ ;
            if(mpp.size() == k-1)
                cnt++ ;
        }    
        return cnt ;
    }
};
