class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size() ;
        if(n <= 2)
            return 0 ;
        int ans =0 ;
        int current =0 ;
        for(int i =2 ; i< n ; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                current += 1 ;
                ans += current ;
            }
            else
                current =0 ;
        }
            return ans ;
        }
       
};
