typedef long long ll ;
class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        ll wt = 0 , t = 0 ;
        sort(bt.begin() ,bt.end()) ;
        int n = bt.size() ;
        for(int i =0 ; i< n ; i++){
            wt += t ;
            t += bt[i] ;
        }
        return wt / n ;
    }
};
