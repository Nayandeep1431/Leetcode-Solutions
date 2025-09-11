class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true ;

        return false ;    
    }

    static bool cmp(const char a , const char b){
        return (a - 'A') < (b - 'A') ;
    }
    string sortVowels(string s) {
        int n = s.length() ;
        string temp = "" ;
        for(int i =0 ; i< n ; i++){
            if(isVowel(s[i]))
                temp += s[i] ;
        }
        sort(temp.begin() , temp.end() , cmp) ;
        int k = 0 ;
        for(int i =0 ; i < n ; i++){
            if(isVowel(s[i])){
                s[i] = temp[k] ;
                k++ ;
            }
        }
        return s ;
    }
};
