class Solution {
    int solve(vector<int> &nums , int k){
        int cnt = 1;
        long long sub = 0 ;
        for(int i =0 ; i< nums.size() ; i++){
            if(sub + nums[i] <= k){
                sub += nums[i] ;
            }
            else{
                sub = nums[i] ;
                cnt++ ;
            }
        }
        return cnt ;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end()); 
        int sum = accumulate(nums.begin(), nums.end(), 0); 

        int low = maxi ;
        int high = sum ;
        while(low <= high ){
            int mid = low + (high - low) / 2;
            int parts = solve(nums , mid) ;
            if(parts > k)
                low = mid +1 ;
            else
                high = mid -1 ;    
        }
        return low ;
    }
};
