
class Solution {
public:
    typedef long long ll;
    
    long long maxSubarrays(int n, vector<vector<int>>& arr) {
       ll ans  =0 ;
       vector<vector<int>> nums(n+1) ;
       for(auto &p : arr){
        int a = min(p[0] , p[1]) ;
        int b = max(p[0] , p[1]) ;

        nums[b].push_back(a) ;
       }

       ll maxi = 0 ;
       ll second = 0 ;
       vector<ll> extra(n+1 , 0) ;

       for(int i = 1 ; i<= n ; i++){
        for(int &u : nums[i]){
            if(u >= maxi){
                second = maxi ;
                maxi = u ;
            }
            else if(u > second)
                second = u ;
        }
        ans += i - maxi ;
        extra[maxi] += maxi - second ;
       }
       ll top = *max_element(extra.begin() , extra.end()) ;
       return ans + top ;
    }
};
