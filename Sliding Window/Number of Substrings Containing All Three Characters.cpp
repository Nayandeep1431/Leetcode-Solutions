class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = s.length() ; 
       vector<int> freq(3,0) ; 
       int cnt = 0 ; 
       int l = 0 ; 
       for(int i =0 ; i< n ; i++){
            char ch = s[i] ; 
            freq[ch -'a']++ ; 
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                cnt += n - i ; 
                freq[s[l] -'a']-- ; 
                l++ ;
            }
       }
       return cnt ;
    }
};
