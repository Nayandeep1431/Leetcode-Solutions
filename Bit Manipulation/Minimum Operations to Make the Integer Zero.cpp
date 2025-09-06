class Solution {
public:
    typedef long long ll ;
    int makeTheIntegerZero(int num1, int num2) {
        ll t  =0 ;
        while(true){
            ll val = (ll) num1 - (ll)t* num2 ;
            if(val < 0)
                return -1 ;
            if(__builtin_popcountll(val) <= t && t <= val)
                return t ;
            t++ ;    
        }
        return -1 ;
    }
};
