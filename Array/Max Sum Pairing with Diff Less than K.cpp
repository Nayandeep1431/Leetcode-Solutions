class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ; 
        sort(arr.begin() , arr.end()) ; 
        int ans = 0 ; 
        
        int prev = arr[n-1] ; 
        for(int i = n-2 ; i>= 0 ; i--){
            int val = arr[i] ;
            
            if(prev - val < k){
                ans += val + prev ; 
                i-- ;
            }
            prev = arr[i] ; 
        }
        return ans ;
    }
};
