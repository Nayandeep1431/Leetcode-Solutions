class Solution {
  public:
    bool weCan(vector<int> &arr, int k , int mid){
        int n = arr.size() ;
        int last = arr[0] ;
        int cnt = 1 ;
        for(int i =1 ; i< n ; i++){
            if(arr[i] - last >= mid){
                cnt++ ;
                last = arr[i] ;
            }
            
            if(cnt >= k)
                return true ;
        }
        return cnt >= k ;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ;
        int low = 1 ;
        sort(arr.begin() , arr.end()) ;
        int high = (arr[n-1] - arr[0]) ;
        while(low <= high){
            int mid = (low + high)/2 ;
            if(weCan(arr ,k , mid))
                low = mid + 1; 
            else
                high = mid - 1 ;
        }
        return high ;
    }
};
