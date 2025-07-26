class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size() ;
        map<char , int> mpp ;
        vector<int> prefix(n) ;
        prefix[0] = travel[0] ;
        int ans = 0 ;
        for(int i = 1 ; i< n ; i++)
            prefix[i] = prefix[i-1] + travel[i] ; 

        for(int i =0 ; i< garbage.size() ; i++){
            string s = garbage[i] ;
            ans += s.length() ;
            for(int j =0 ; j< s.length() ; j++){
                char ch = s[j] ;
                mpp[ch] = i ;
            }
        }
        for(auto &it : mpp){
            if(it.second != 0)
                ans += prefix[it.second-1] ;
        }
        return ans ;
    }
};
