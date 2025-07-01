class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        int l = 0 ;
        int maxi = 1 ;
        long long currSum =0 ;
        for(int i =0 ; i< n ; i++){
            long long target = nums[i] ;
            currSum += nums[i] ;
            long long windowSum = (i - l+1) * target ;
            long long ops = windowSum - currSum ;

            while(ops > k){
                currSum -= nums[l] ;
                l++ ;
                ops = (i-l+1) * target - currSum ;
            }

            maxi = max(maxi , i-l+1) ;
        }
        return maxi ;
    }
};
