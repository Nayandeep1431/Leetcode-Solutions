class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size() ;
        int cnt = 0 ;
        sort(nums.begin() , nums.end()) ;
        int prev = 0 ;
        for(int i =0 ; i < n ; i++ ){
            int ele = nums[i] ;
            int ind = upper_bound(nums.begin()+ prev + 1 , nums.end() , ele) - nums.begin() ;

            if(ind != n){
                cnt++ ;
                prev = ind ;
            }
            else
                break;
        }
        return cnt ;
    }
};
