class Solution {
public:
    typedef long long ll ;
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size() ;
        ll ans = 0 ;
        ll cnt = 0 ;
        for(int i =0 ; i< n ; i++ ){
            int ele = nums[i] ;
            if(ele == 0)
                cnt++ ;
            else{
                ll val = (cnt* (cnt+1))/2 ;
                ans += val ;
                cnt = 0 ;
            }    
        }
        if(cnt > 0)
            ans += (cnt* (cnt+1))/2 ;
        return ans ;
    }
};
