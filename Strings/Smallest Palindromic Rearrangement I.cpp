class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length() ; 
        vector<int> freq(26 , 0) ; 
        for(char ch : s){
            freq[ch - 'a']++ ; 
        }
        int l =0 , r = n-1 ; 
        for(int i =0 ; i< 26 ; i++){
            if(freq[i] == 0)
                continue ; 

            if(freq[i] % 2 != 0){ 
                s[n/2] = i + 'a' ; 
                freq[i] = freq[i] - 1 ; 
            }       

            while(freq[i] > 0){
                s[l] = i +'a' ; 
                s[r] = i + 'a' ; 
                l++; 
                r-- ; 
                freq[i] -= 2 ; 
            }
        }
        return s ;
    }
};
