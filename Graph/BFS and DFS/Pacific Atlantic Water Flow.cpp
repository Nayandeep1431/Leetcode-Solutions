class Solution {
public:
    int n , m ;
    typedef vector<vector<int>> v ; 
    int dr[4] = {1 ,-1 , 0 ,0} ;
    int dc[4] = {0 , 0 , 1 ,-1} ; 

    void dfs(int r , int c , v &arr , v &grid){
        for(int i =0 ; i< 4 ; i++){
            int nx = r + dr[i] ;
            int ny = c + dc[i] ; 

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] >= grid[r][c] && arr[nx][ny] == 0){
                arr[nx][ny] = 1 ; 
                dfs(nx , ny , arr , grid) ; 
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size() ;
        m = heights[0].size() ; 

        v pv( n , vector<int> (m , 0)) ; 
        v av (n , vector<int> (m , 0)) ; 

        for(int i =0 ; i < m ;i++){
            pv[0][i] = 1 ; 
            av[n-1][i] = 1 ; 
        }

        for(int i =0 ; i< n ; i++){
            pv[i][0] = 1 ;
            av[i][m-1] = 1;
        }

        for(int i =0 ; i< n ; i++){
            dfs(i , 0 , pv , heights) ; 
            dfs(i , m-1 , av ,heights) ;
        }

        for(int i =0 ; i< m ; i++){
            dfs(0 , i ,pv , heights) ; 
            dfs(n-1 , i , av , heights) ; 
        }

        v ans ; 
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j< m ; j++){
                if(pv[i][j] == 1 && av[i][j] == 1)
                    ans.push_back({i , j}) ; 
            }
        }
        return ans ;
    }
};
