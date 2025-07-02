class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() ;
        int flips = 0 ;

        int flipcnt = 0 ;
        vector<bool>isFlipped(n , 0) ; 
        for(int i =0 ; i< n ; i++){
            if(i >= k && isFlipped[i-k] == true)
                flipcnt -- ;

            if(flipcnt % 2 == nums[i]){
                if(i + k > n)
                    return -1 ;

                flips++ ;
                flipcnt ++ ;
                isFlipped[i] = true ;     
            }    
        }
        return flips ;
    }
};
