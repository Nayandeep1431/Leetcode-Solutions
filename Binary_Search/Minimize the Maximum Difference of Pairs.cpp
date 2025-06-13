class Solution {
    bool check(vector<int> &arr , int p , int mid){
        int i =0 ; 
        int n = arr.size() ;
        int cnt = 0 ;
        while(i < n-1){
            if(abs(arr[i] - arr[i+1]) <= mid){
                cnt++ ;
                i += 2 ;
            }
            else
                i++ ;
        }
        return cnt >= p ;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;

        int l =0 ;
        int r = nums[n-1] - nums[0] ;
        int res = INT_MAX ;

        while(l <= r){
            int mid = l + (r-l) / 2;
            if(check(nums , p , mid)){
                res = mid ;
                r = mid - 1 ;
        }    
            else
                l = mid +1 ;    
        }
        return res ;
    }
};
