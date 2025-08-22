class Solution {
public:
    int maxElement(vector<vector<int>>&mat , int n , int m){
        int ans = INT_MIN ;
        int ind = -1 ;
        for(int i =0 ;i < n ; i++){
            if(mat[i][m] > ans){
                ans = mat[i][m] ;
                ind = i ;
            }
        }
        return ind ;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;

        int low = 0 , high = m-1 ;
        while(low <= high){
            int mid = (low + high) /2 ;
            int maxi = maxElement(mat , n , mid) ;
            int left = mid - 1 >= 0 ? mat[maxi][mid-1] : -1 ;
            int right = mid +1 < m ? mat[maxi][mid+1] : -1 ;

            if(mat[maxi][mid] > left && mat[maxi][mid] > right)
                return {maxi , mid} ;
            else if(mat[maxi][mid] < left)
                high = mid - 1 ;
            else
                low = mid + 1 ;        
        }
        return {-1 , -1} ;
    }
};
