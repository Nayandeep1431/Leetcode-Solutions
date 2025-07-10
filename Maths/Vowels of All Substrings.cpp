class Solution {
    typedef long long ll ;
    bool isVowel(char ch){
        if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch =='u')
            return true ;

        return false ;    
    }
public:
    long long countVowels(string word) {
        ll n = word.length() ;
        ll ans = 0 ;

        for(ll i =0 ; i < n ; i++){
            char ch = word[i] ;
            if(isVowel(ch)){
                ans += (i+1) * (n-i) ;
            }
        }
        return ans ;
    }
};
