class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size() ;
        int low = 0 , high = n-1 ;
        int mini = INT_MAX ;
        int minInd = -1 ;
        
        while(low <= high){
            int mid = (low + high) / 2 ;
            if(arr[low] <= arr[mid]){
                if(arr[low] < mini){
                    mini = arr[low] ;
                    minInd = low ;
                }
                low = mid + 1 ;
            }
            else{
                if(arr[mid] <= mini){
                    mini = arr[mid] ;
                    minInd = mid ;
                }
                high = mid - 1 ;
            }
        }
        return minInd ;
    }
};
