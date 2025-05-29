class Solution {
    int solve(vector<int> &arr , int mid){
        int n = arr.size() ;
        int time= 1 ;
        int val = 0 ;
        for(int i =0 ; i< n ; i++){
            if(arr[i] + val <= mid)
                val += arr[i] ;
            else{
                time++ ;
                val = arr[i] ;
            }    
        }
        return time ;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ;
        
        int low = *max_element(arr.begin() , arr.end()) ;
        int high = accumulate(arr.begin() , arr.end() , 0) ;
        while(low <= high){
            int mid = (high + low) / 2 ;
            int painters = solve(arr , mid) ;
            if(painters > k)
                low = mid + 1 ;
            else
                high = mid - 1;
        }
        return low ;
    }
};
