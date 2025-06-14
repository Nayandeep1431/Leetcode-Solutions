class Solution {
    bool check(vector<int> &arr , int n , int mid){
        vector<long long > nums (arr.begin() ,arr.end()) ;

        for(int i =0 ; i< n-1 ; i++){
            if(nums[i] > mid)
                return false ;

            long long buffer = mid - nums[i] ;
            nums[i+1] -= buffer ;    
        }
        return nums[n-1] <= mid ;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size() ;

        int l =0 ;
        int r = *max_element(nums.begin(), nums.end()) ;
        int res = 0 ;

        while(l <= r){
            int mid = l + (r-l) /2 ;
            if(check(nums , n , mid)){
                res = mid ;
                r = mid - 1 ;
            }
            else
                l = mid + 1 ;
        }
        return res ;
    }
};
