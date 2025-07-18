class Solution {
  public:
  int fact(int n){
      int ans = 1 ;
      for(int i = 1; i <= n ; i++){
          ans *= i ;
      }
      return ans ;
  }
  bool isVowel(char ch){
      if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true ;
    else
        return false ;
  }
    int vowelCount(string& s) {
        // code here
        unordered_map<char ,int> mpp ;
        for(int i =0 ; i < s.length() ; i++){
            char ch = s[i] ;
            if(isVowel(ch))
                mpp[ch] ++ ;
        }
        if(mpp.size() == 0)
            return 0 ;
        int ans = fact(mpp.size()) ;
        for(auto it : mpp){
            ans *= it.second ;
        }
        return ans ;
    }
};
