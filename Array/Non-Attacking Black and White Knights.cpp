class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int dr[8] = {2 , 2 , -2 , -2 , 1 ,1 ,-1 , -1} ; 
        int dc[8] = {1 , -1 , 1 , -1 , 2 , -2 , 2 ,-2 } ; 
        
        int ans = 0 ; 
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j < m ; j++){
                int cnt = 1 ; 
                for(int k = 0 ; k < 8 ; k++){
                    int nx = i + dr[k] ;
                    int ny = j + dc[k] ; 
                    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                        cnt++ ;
                }
                ans += (n*m)- cnt ;
            }
        }
        return ans ; 
    }
};
