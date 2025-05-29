class Solution {
    int solve(vector<int> &arr , int mid){
        int n = arr.size() ;
        int cnt = 1 ;
        int pages = 0 ;
        for(int i =0 ; i< n ; i++){
            if(pages + arr[i] <= mid)
                pages += arr[i] ;
            else{
                cnt++ ;
                pages = arr[i] ;
            }    
        }
        return cnt ;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size() ;
        if(k > n)
            return -1 ;
        int low = *max_element(arr.begin() , arr.end()) ;
        int high = accumulate(arr.begin() , arr.end(), 0) ;
        
        while(low <= high){
            int mid = (high + low) / 2 ;
            int students = solve(arr , mid) ;
            if (students > k)
                low = mid +1 ;
            else
                high = mid -1 ;
        }
        return low ;
    }
};
