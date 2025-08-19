class Solution {
public:
    typedef long long ll;
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 0 ;
        int n = prices.size() ;
        ll cnt = 1 ;
        int prev = prices[0] ;

        for(int i =1 ; i< n ; i++){
            int ele = prices[i] ;
            if(ele  == prev - 1){
                cnt++ ;
            }
            else{
                ans += (cnt * (cnt +1)) / 2 ;
                cnt = 1 ;
            }
            prev = ele ;
        }
        ans += (cnt * (cnt +1)) / 2 ;
        return ans ;
    }
};
