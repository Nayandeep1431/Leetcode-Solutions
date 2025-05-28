class Solution {
    long long solve(vector<int> &nums , int mid){
        long long ans = 0 ;
        int n = nums.size() ;
        for(int i =0 ; i< n ; i++){
            ans += (nums[i] + mid - 1)/ mid ;
        }
        return ans ;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size() ;
        int low = 1 ;
        int maxi = *max_element(nums.begin() , nums.end()) ;
        int high = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long cnt = solve(nums , mid) ;
            if(cnt <= threshold )
                high = mid -1 ;
            else
                low = mid + 1 ;    
        }
        return low ;
    }
};
