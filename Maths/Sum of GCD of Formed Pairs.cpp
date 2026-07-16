class Solution {
public:
    typedef long long ll ; 

    long long gcdSum(vector<int>& nums) {
        int n = nums.size() ; 
        vector<ll> pre(n) ; 
        int maxi = nums[0] ; 

        for(int i = 0 ; i<n ; i++ ){
            maxi = max(maxi , nums[i]) ;
            pre[i] = gcd(maxi , nums[i]) ; 
        }

        int i = 0 , j = n-1 ; 
        ll ans = 0 ; 
        sort(pre.begin() , pre.end()) ; 
        while(i < j){
            ans += gcd(pre[i] , pre[j]) ; 
            i++ ; 
            j-- ; 
        }
        return ans ; 
    }
};
