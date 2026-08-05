class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        int m = a.size() ;
        vector<int> prefix(n+1 , 0) ; 
        for(int i = 0 ; i< m ; i++){
            int s = a[i] ; 
            int e = b[i] +1 ; 
            prefix[s] += k[i] ;
            prefix[e] -= k[i] ; 
        }
        int maxi = prefix[0] ; 
        for(int i = 1  ; i< n ; i++){
            prefix[i] += prefix[i-1] ; 
            maxi = max(maxi, prefix[i]) ; 
        }
        return maxi ; 
    }
};
