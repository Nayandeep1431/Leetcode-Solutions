class Solution {
  public:
    int n  ; 
        
    bool solve(vector<int>& arr, int &idx, int low, int high) {
        if (idx == arr.size())
            return true;
    
        if (arr[idx] < low || arr[idx] > high)
            return true;     
    
        int root = arr[idx++];
    
        solve(arr, idx, low, root);
        solve(arr, idx, root, high);
    
        return true;
    }
    
    bool canRepresentBST(vector<int>& arr) {
        int idx = 0;
        solve(arr, idx, INT_MIN, INT_MAX);
        return idx == arr.size();
}
};
