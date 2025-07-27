class Solution {
  public:
    int balanceSums(vector<vector<int>>& matrix) {
        // code here
        int n = matrix.size() ;
        vector<int> values(n);
        int need = 0;
        
        for(int i = 0;i<n;i++){
            int row,col;
            row = col = 0;
            
            for(int j = 0;j<n;j++){
                row += matrix[j][i];
                col += matrix[i][j];
            }
            need = max({need,row,col});
            values[i] = row;
        }
        
        int ans = 0;
        for(auto i : values){
            ans += need - i;
        }
        
        return ans;
    }
};
