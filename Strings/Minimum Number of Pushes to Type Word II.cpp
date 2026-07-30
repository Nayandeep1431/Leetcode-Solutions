class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size() ; 
        vector<int> freq(26 , 0) ; 
        for(char ch : word)
            freq[ch - 'a']++ ; 

        sort(freq.rbegin() , freq.rend()) ;
        int ans = 0 ; 
        int d = 0 ;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] != 0)
                d++ ; 

            int num = (d + 7) / 8 ; 
            ans += freq[i] * num ;     
        } 
        return ans ;     
    }
};
