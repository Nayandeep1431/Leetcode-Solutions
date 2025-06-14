typedef long  long ll ;
class Solution {
    ll solve(vector<int>& nums, vector<int>& cost ,ll mid){
        ll ans = 0 ;
        for(int i =0 ; i< nums.size() ; i++){
            ll diff = abs(nums[i] - mid) ;
            ans += (diff * cost[i]) ;
        }
        return ans ;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll l = *min_element(nums.begin() , nums.end()) ;
        ll r = *max_element(nums.begin() , nums.end()) ;
        ll ans = LLONG_MAX ;
        while(l <= r){
            ll mid = l + (r-l)/2 ;
            ll cost1 = solve(nums , cost , mid) ;
            ll cost2 = solve(nums , cost , mid+1) ;

            ans = min(cost1 , cost2) ;

            if(cost2 > cost1)
                r = mid -1 ;
            else
                l = mid+1 ;    
        }
        return ans ;
    }
};
