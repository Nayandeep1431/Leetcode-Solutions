class Solution {
public:
    typedef vector<vector<int>> v ;
    typedef pair<int , int> p ;  
    int dr[4] = {1, -1, 0 , 0} ; 
    int dc[4] = {0, 0,1, -1} ; 
    int n , m ;

    void dfs(int i , int j , v &grid , v &vis , queue<p> &q ){
        vis[i][j] = true ; 
        q.push({i, j}) ; 

        for(int r = 0 ; r < 4; r++){
            int nx = i + dr[r] ; 
            int ny = j + dc[r] ;

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] == 1)
                dfs(nx , ny , grid , vis ,q) ; 
        }
    }

 int bfs(queue<p> &q, v &grid, v &vis){

    int steps = 0;

    while(!q.empty()){

        int size = q.size();

        while(size--){

            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){

                int nx = x + dr[k];
                int ny = y + dc[k];

                if(nx >= 0 && ny >= 0 &&
                   nx < n && ny < m &&
                   !vis[nx][ny]){

                    if(grid[nx][ny] == 1)
                        return steps;

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        steps++;
    }

    return -1;
}
    int shortestBridge(vector<vector<int>>& grid) {
         n = grid.size() ;
         m = grid[0].size() ; 

        vector<vector<int>> vis(n, vector<int>(m , 0)) ; 
        queue<pair<int , int>> q ; 
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j< m ; j++){
                if(grid[i][j] == 1){
                    dfs(i , j ,grid, vis , q ) ; 
                    return bfs(q , grid , vis) ; 
                }
            }
        }
        return -1 ; 
    }
};
