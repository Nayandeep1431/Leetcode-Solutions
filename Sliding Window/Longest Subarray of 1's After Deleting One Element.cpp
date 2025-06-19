class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size() ;
        int l =0 , r =0 ;
        int maxi = 0 ;
        int cnt0 = 0 ;
        while(r < n){
            int ele = arr[r] ;
            if(ele == 0)
                cnt0++ ;

            while(l <= r && cnt0 > 1 ){
                if(arr[l] == 0)
                    cnt0-- ;
                l++ ;    
            }

            maxi = max(maxi , r-l) ;
            r++ ;
        }
        return maxi ;
    }
};
