class Solution {
    bool isSorted(vector<int> &nums){
        int n = nums.size() ;
        for(int i =0 ; i< n-1 ; i++){
            if(nums[i] < nums[i+1])
                return false ;
        }
        return true ;
    }
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size() ;
        int mini = nums[0] ;
        int maxDiff = INT_MIN ;

        if(isSorted(nums))
            return -1 ;

        for(int i = 1 ; i< n ; i++){
            maxDiff = max(maxDiff , nums[i] - mini) ;
            mini = min(mini , nums[i]) ;
        }
        return maxDiff ;
    }
};
