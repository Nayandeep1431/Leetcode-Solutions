class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size() ;
        int maxi = INT_MIN ;
        for(int i =0 ; i < n-1 ; i++){
            int diff = abs(nums[i] - nums[i+1] ) ;
            maxi = max(maxi , diff) ;
        }
        maxi = max(maxi , abs(nums[n-1] - nums[0])) ;
        return maxi ;
    }
};
