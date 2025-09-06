class Solution {
public:
    typedef long long ll ;
    ll solve(ll l ,ll r){
        ll L = 1 ,  s = 1;
        ll cnt = 0 ;
        while(L <= r){
            ll R = L*4 -1 ;

            ll start = max(L ,l) ;
            ll end =  min(r , R) ;

            if(start <= end){
                cnt += (end - start+1) * s ;
            }
             L = L*4 ; 
             s++ ;
        }
        return cnt ;
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size() ;
        ll res = 0 ;
        for(auto q : queries){
            ll l = q[0] ;
            ll r = q[1] ;
            
            ll steps = solve(l , r) ;
            res += (steps +1) / 2 ;
        }
        return res ;
    }
};
