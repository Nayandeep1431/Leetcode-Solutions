class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> left(n , 0) , right(n , 0) ; 
        left[0] = arr[0] ; 
        right[n-1] = arr[n-1] ; 
        int ans = max(left[0] , right[n-1]) ; 

        for(int i = 1; i<n ; i++){
            left[i] = max(arr[i] , arr[i] + left[i-1]) ;
            ans = max(ans , left[i]) ; 
        }
        for(int j =n-2 ; j>=0 ; j--){
            right[j] = max(arr[j] , arr[j] + right[j+1]) ;
            ans = max(ans , right[j]) ;
        }
        for(int i = 1; i<n-1 ; i++){
            ans = max(ans , left[i-1] + right[i+1]) ;
        }
        return ans ;
    }
};
