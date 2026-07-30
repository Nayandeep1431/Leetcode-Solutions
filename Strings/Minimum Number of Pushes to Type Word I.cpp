class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size() ; 
        vector<int> cnt(26 , 0) ; 
        int d = 0 ; 
        for(char ch : word){
            if(cnt[ch - 'a'] == 0)
                d++ ; 

            if(d > 8 && d <= 16)
                cnt[ch - 'a'] = 2 ; 
            else if(d > 16 && d <= 24)
                cnt[ch - 'a'] = 3 ; 
            else if(d > 24)
                cnt[ch - 'a'] = 4 ;
            else
                cnt[ch - 'a'] = 1 ;                
        }
        int ans = 0 ; 
        for(char ch : word){
            ans += cnt[ch - 'a'] ;
        }
        return ans ;
    }
};
