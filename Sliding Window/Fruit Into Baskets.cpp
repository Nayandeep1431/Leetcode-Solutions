class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ;
        unordered_map<int , int> mpp ;
        int l =0 ;
        int r = 0 ;
        int maxi = 0 ;
        while(r < n){
            int fr = fruits[r] ;
            mpp[fr]++ ;
            while(mpp.size() > 2){
                mpp[fruits[l]]-- ;
                if(mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]) ;

                l++ ;    
            }
            maxi = max(maxi , r - l + 1) ;
            r++ ;
        }
        return maxi ;
    }
};
