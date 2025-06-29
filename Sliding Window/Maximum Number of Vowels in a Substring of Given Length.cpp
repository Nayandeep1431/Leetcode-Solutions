class Solution {
public:
    bool isVowel(char ch){
        if(ch =='a' || ch == 'e' || ch =='i' || ch == 'o' || ch =='u')
            return true ;

        return false ;    
    }
    int maxVowels(string s, int k) {
        int n = s.length() ;
        int cnt = 0 ;
        int maxi = INT_MIN ;

        for(int i =0 ; i< k ; i++){
            char ch = s[i] ;
            if(isVowel(ch))
                cnt++ ;
        }
        maxi = max(maxi , cnt) ;
        for(int i = k ; i < n ; i++){
            char prev = s[i-k] ;
            if(isVowel(prev))
                cnt-- ;

            char ch = s[i] ;
            if(isVowel(ch))
                cnt++ ;

            maxi = max(maxi , cnt) ;        
        }
        return maxi ;
    }
};
