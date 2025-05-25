class Solution {
    bool solve(string s, char ch){
        int n = s.length() ;
        for(int i =0 ; i < n ; i++){
            if(s[i] == ch)
                return true ;
        }
        return false ;
    }
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size() ;
        vector<int> ans ;
        for(int i =0 ; i< n ; i++){
            if(solve(words[i] , x))
                ans.push_back(i) ;
        }
        return ans ;
    }
};
