class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
       int n = word.length() ;  
       unordered_map<string , int> mpp ; 
        for(int i =0 ; i< n ; i+=k){
            string sub = word.substr(i , k) ;
            mpp[sub]++ ; 
        }

        int maxi = 0 ; 
        string top = "" ; 
        for(auto it : mpp){
            if(it.second > maxi){
                maxi = it.second ; 
                top = it.first ; 
            }
        }
        int cnt= 0 ; 
        for(int i =0 ; i< n ; i+=k){
            string sub = word.substr(i , k) ; 
            if(sub != top)  
                cnt++ ; 
        }
        return cnt ;
    }
};
