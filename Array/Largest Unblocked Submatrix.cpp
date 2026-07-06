class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // code here
        vector<int> row ,col ; 
        
        for(int i =0 ; i< k ;i++){
            row.push_back(arr[i][0])  ;
            col.push_back(arr[i][1]) ; 
        }
        
        int maxRow = 0 , maxCol = 0 ; 
        int prev = 0 ; 
        
        sort(row.begin() , row.end()) ; 
        sort(col.begin() ,col.end()) ; 
        
        for(int i =0 ; i < k ; i++){
            maxRow = max(maxRow ,row[i] - prev - 1) ; 
            prev = row[i] ; 
        }
        maxRow = max(maxRow , n- prev) ; 
        prev = 0 ; 
        
        for(int i =0 ; i< k ; i++){
            maxCol = max(maxCol , col[i] - prev - 1) ; 
            prev = col[i] ;
        }
        maxCol = max(maxCol , m - prev) ; 
        
        return maxRow * maxCol ; 
    }
};
