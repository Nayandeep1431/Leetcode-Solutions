class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size() ;
        int total = accumulate(nums.begin() , nums.end() , 0) ;
        sort(nums.rbegin() , nums.rend()) ;
        vector<int> ans ;
        int sum = 0 ;
        for(int i = 0 ; i< n ; i++){
            sum += nums[i] ;
            ans.push_back(nums[i]) ;
            total -= nums[i] ;
            if(sum > total)
                return ans ;
        }
        return ans ;
    }
};
