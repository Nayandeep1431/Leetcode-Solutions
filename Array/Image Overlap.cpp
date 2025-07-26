class Solution {
public:
    int count(vector<vector<int>>&a , vector<vector<int>>&b , int row , int col){
        int n = a.size() ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j< n ; j++){
                int nx = i + row ;
                int ny = j + col ;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n )
                    continue ;

                if(a[i][j] == 1 && b[nx][ny] == 1)
                    cnt++ ;    
            }
        }
        return cnt ;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size() ;
        int maxi =0 ;
        for(int i = -n+1 ; i< n ; i++){
            for(int j = -n+1 ; j< n ; j++){
                int cnt = count(img1 , img2 , i , j) ;
                maxi= max(maxi , cnt) ;
            }
        }
        return maxi ;
    }
};
