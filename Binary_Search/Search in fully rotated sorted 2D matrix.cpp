class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size() ;
        int m = mat[0].size() ;
        
        // Naive Approach
        // for(int i =0 ; i< n ; i++){
        //     for(int j =0 ; j < m ; j++){
        //         if(mat[i][j] == x)
        //             return true ;
        //     }
        // }
        
        // Binary Search
        int l = 0 ;
        int h = n*m - 1 ;
        while(l <= h){
            int mid = (l + h) / 2 ;
            int row = mid / m ;
            int col = mid % m ;
            int val = mat[row][col] ;
            
            if(val == x)
                return true ;
            
            int lowVal = mat[l/ m][l % m] ;
            int highVal = mat[h/m][h % m] ;
            
            if(lowVal <= val){
                if(lowVal <= x && x < val)
                    h = mid - 1 ;
                else
                    l =mid +1 ;
            }
            else{
                if(val < x && x <= highVal)
                    l = mid +1 ;
                else
                    h = mid - 1 ;
            }
        }
        return false ;
    }
};
