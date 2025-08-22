class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n = mat.size() ;
        int m = mat[0].size() ;
        
        int r = 0 , c = m-1 ;
        
        while(r < n && c >=0){
            int ele = mat[r][c] ;
            if(ele == x)
                return true ;
            else if(ele > x)
                c-- ;
            else
                r++ ;
        }
        return false ;
    }
};
