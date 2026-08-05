class Solution {
  public:
    int solve(int k , vector<int> &arr){
        int n = arr.size() ; 
        int sum = 0 ; 
        int cnt = 0 ; 
        
        int l =0 , r = 0 ; 
        while(r < n ){
            sum += arr[r] ; 
            while(sum > k){
                sum -= arr[l] ; 
                l++ ; 
            }
            cnt += (r-l+1) ; 
            r++ ; 
        }
        return cnt  ;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return solve(r , arr) - solve(l-1 ,arr) ; 
    }
};
