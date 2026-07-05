class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n = s.length() ; 
        vector<int> first(26 , -1) , last(26 ,-1) ; 
        int maxi = -1 ; 
        for(int i =0 ; i< n ; i++){
            char ch = s[i] ; 
            if(first[ch - 'a'] == -1){
                first[ch - 'a'] = i ; 
                last[ch - 'a'] = i ;
            }
            else{
                last[ch - 'a'] = i ; 
                maxi = max(maxi , last[ch - 'a'] - first[ch- 'a'] - 1 ) ; 
            }
        }
        return maxi ;
    }
};
