class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "" ;

        map<char , int> mpp ;
        for(int i =0 ; i< t.length() ; i++){
            mpp[t[i]]++ ;
        }    
        int cnt = t.size() ;
        int mini = INT_MAX ;
        int start = -1 ;

        int i =0, j  =0 ;
        while(j < s.length()){
            char ch = s[j] ;
            if(mpp[ch] > 0){
                cnt-- ;
            }
            mpp[ch]-- ;
            while(cnt == 0){
                int curr = j-i+1 ;
                if(curr < mini){
                    mini = curr ;
                    start = i ;
                }
                mpp[s[i]]++ ;
                if(mpp[s[i]] > 0)
                    cnt++ ;

                i++ ;    
            }
            j++ ;
        }
        return (mini == INT_MAX) ? "" : s.substr(start , mini) ;
    }
};
