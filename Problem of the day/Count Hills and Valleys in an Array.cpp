class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size() ;
        int hill = 0 ;
        int valley = 0 ;
        int prev = -1 ;
        for(int i =1 ; i< n-1 ; i++){
            int ele = nums[i] ;
            if(ele == prev)
                continue ;

            int back = -1 , front = -1 ;
            for(int j =i-1 ; j>=0 ; j--){
                if(nums[j] != ele){
                    back= nums[j] ;
                    break ;
                }
            }    
            for(int j = i+1 ; j< n ; j++){
                if(nums[j] != ele){
                    front = nums[j] ;
                    break ;
                }
            }
            if(back == -1 || front == -1)
                continue ;

            if(back > ele && front > ele)
                hill++ ;
            else if(back < ele && front < ele)
                valley++ ;

            prev = ele ;    
        }
        return hill + valley ;
    }
};
