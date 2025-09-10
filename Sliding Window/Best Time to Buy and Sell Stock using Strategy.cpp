class Solution {
public:
    typedef long long ll ;
    long long maxProfit(vector<int>& prices, vector<int>& s, int k) {
        int n = prices.size() ;
        vector<ll> val(n ) ;
        ll maxi = LLONG_MIN ;
        ll sum =0  ;
        for(int i =0 ; i< n ; i++){
            val[i] = prices[i] * s[i] ;
            sum += val[i] ;
        }
        maxi = max(maxi , sum) ;
        for(int i =0 ; i< k ; i++){
            sum -= val[i] ;
            if(i >= k / 2)
                sum += prices[i]  ;
        }
        maxi = max(maxi , sum) ;
        for(int i = k ; i< n ; i++){
            sum += val[i-k] ;
            sum -= val[i] ;
            sum += prices[i] ;
            sum -= prices[i - k/2] ;

            maxi = max(maxi , sum) ;
        }
        return maxi ;
    }
};
