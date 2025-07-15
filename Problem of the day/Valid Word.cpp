class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E'
        || ch == 'U' || ch == 'O' || ch == 'I')
            return true ;

        return false ;    
    }
    bool isValid(string word) {
        int n = word.size() ;

        if(word.size() < 3)
            return false ;

        bool number = true , vowel = false , consonant = false ;
        for(int i = 0 ; i < n ; i++){
            char ch = word[i] ;
            if(ch == '@' || ch == '$' || ch == '#') 
                return false ;

            if(ch >= '0' && ch <= '9')
                number = true ;
            else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                if(isVowel(ch))
                    vowel = true ;
                else
                    consonant = true ;    
            }       
        }
        
            if(vowel && number && consonant)
                return true ;
        return false ;
    }
};
