class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        int cnt = 0 ;
        for(int i =0 ; i< n ; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue ;

            int ele = nums[i] ;
            auto it = lower_bound(nums.begin() + i+1 , nums.end() , ele + k) ;
            if(it != nums.end()){
                if(abs(ele - *it) == k)
                    cnt++ ;
            }    
        }
        return cnt ;
    }
};
