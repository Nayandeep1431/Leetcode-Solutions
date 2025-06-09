typedef long long ll ;
class Solution {
public:
    ll count (ll curr , ll next , ll n){
        ll cntNum = 0 ;
        while(curr <= n){
            cntNum += next - curr ;
            curr = curr * 10 ;
            next = next * 10 ;
            next = min(next , n+1) ;
        }
        return cntNum ;
    }
    int findKthNumber(int n, int k) {
        ll curr = 1;
        k -=1 ;
        while( k > 0){
            ll cnt = count(curr , curr + 1 ,n ) ;
            if(cnt <= k){
                curr++ ;
                k-= cnt ;
            }
            else{
                curr *= 10 ;
                k -= 1 ;
            }
        }
        return curr ;
    }
};
