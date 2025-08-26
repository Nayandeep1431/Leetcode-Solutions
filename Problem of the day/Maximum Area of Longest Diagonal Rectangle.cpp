class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int n = arr.size();
        double maxRoot = 0.0 ;
        int  maxArea = 0 ;
        for(auto it : arr){
            int l = it[0] ;
            int b = it[1] ;

            double root = sqrt(l*l + b*b) ;
            if(root > maxRoot){
                maxRoot = root ; 
                maxArea = l*b ;
            }
            else if(root == maxRoot)
                maxArea = max(maxArea , l*b) ;
        }
        return maxArea ;
    }
};
