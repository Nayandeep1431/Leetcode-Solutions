class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        unordered_set<int> rst ;
        unordered_set<int> cst ;
        for(int row = 0 ; row < grid.size() ; row++){
            for(int col =0 ; col < grid[0].size() ; col++){
                if(grid[row][col] == 1){
                   rst.insert(row) ;
                   cst.insert(col) ;
                }
            }
        }
        int maxRow =INT_MIN ;
        int minRow = INT_MAX ;
        int maxCol =INT_MIN ;
        int minCol = INT_MAX ;
        for(auto it : rst){
            maxRow = max(maxRow , it) ;
            minRow = min(minRow , it) ;
        }
        int r = 1  ;
        if(maxRow != minRow)
            r = maxRow - minRow +1 ;

        for(auto it : cst){
            maxCol = max(maxCol , it) ;
            minCol = min(minCol , it) ;
        }    
        int c = 1;
        if(minCol != maxCol)
            c = maxCol - minCol +1 ;

        return r * c ;
    }
};
