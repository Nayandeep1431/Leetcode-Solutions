class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ; 
        unordered_map<int , int> mpp ;
        
        int cnt = 0 ; 
        for(int i : arr){
            int val = i ; 
            val = val % k ; 
            int rem = (val == 0) ? 0 : k - val ;
            
            cnt += mpp[rem] ;
            mpp[val]++ ; 
        }
        return cnt ; 
    }
};
