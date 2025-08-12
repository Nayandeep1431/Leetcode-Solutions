class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ;
        int cnt = 0 ;
        
        int total = (n+1) / 2 ;
        vector<int> r ;
        for(int i =0 ; i < n ; i++){
            int ele = arr[i] ;
            int rem = ele % k ;
            if(rem == 0)
                cnt++ ;
            
            else{
                r.push_back(k - rem) ;
            }    
        }
        total = total - cnt ;
        if(total <= 0)
            return 0 ;
        
        sort(r.begin() , r.end()) ;
        int ans  =0 ;
        for(int i = 0 ; i< total ; i++){
            ans += r[i] ;
        }
        return ans ;
    }
};
