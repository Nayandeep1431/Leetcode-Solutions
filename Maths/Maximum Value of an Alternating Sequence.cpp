class Solution {
public:
    typedef long long ll ; 
    long long maximumValue(int n, int s, int m) {
        if(n == 1)
            return s ;
        ll x =n/ 2 ; 
        ll ans = s + (x * m) - (x-1) ; 
        return ans ;
    }
};
