class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        
        // code here
        int n = arr.size() ; 
        int ans = 0 ; 
        sort(arr.begin() , arr.end()) ; 
        for(int i =0 ; i< n ; i++){
            int lb = lower_bound(arr.begin() , arr.end() , arr[i] + k ) - arr.begin() ; 
                ans += (lb - i - 1) ; 
            
        }
         return ans ; 
    }
};
