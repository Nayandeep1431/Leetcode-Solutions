class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size() ;
        sort(points.begin() ,points.end()) ;
        int cnt = 1 ;
        int end = points[0][1] ;

        for(int i = 1; i< n ; i++){
            int start = points[i][0] ;
            if(start <= end){
                end = min(end , points[i][1]) ;
            }
            else{
                cnt++ ;
                end = points[i][1] ;
            }
        }
        return cnt ;
    }
};
