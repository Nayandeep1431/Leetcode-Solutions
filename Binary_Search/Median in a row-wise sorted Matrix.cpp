class Solution {
public:
    int upperBound(vector<int> &arr, int x, int n) {
        int ans = n;
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int count(vector<vector<int>> &mat, int mid) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(mat[i], mid, m);
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        
        int req = (n * m) / 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = count(mat, mid);
            if (cnt <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
