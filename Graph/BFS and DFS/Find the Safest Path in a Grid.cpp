class Solution {
public:
    typedef pair<int , int> p ; 
    typedef vector<vector<int>> v ;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool check(v &dist , int mid){
        int n = dist.size() ; 
        queue<p> q ; 
        q.push({0 , 0}) ; 
        v vis(n , vector<int> (n , 0)) ;
        vis[0][0] = 1 ; 

        if(dist[0][0] < mid)
            return false ; 
            
        while(!q.empty()){
            int i = q.front().first ; 
            int j = q.front().second ; 
            q.pop() ; 

            if(i == n-1 && j == n-1)
                return true ;

            for(vector<int> &d : dir){
                int nx = i + d[0] ; 
                int ny = j + d[1] ; 

                if(nx >=0 && ny >=0 && nx < n && ny < n && !vis[nx][ny]){
                    if(dist[nx][ny] < mid)
                        continue ;
                    q.push({nx , ny}) ; 
                    vis[nx][ny] = true ;    
                }
            }    
        }
        return false ;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        
        v dist(n , vector<int> (n , -1)) ; 
        v vis(n , vector<int>(n , 0)) ; 
        queue<p> q ; 
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j< n ; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1 ; 
                    q.push({i, j}) ; 
                }
            }
        }
        int level  =0 ; 
        int maxi =0 ;
        while(!q.empty()){
            int size = q.size() ; 
            
            while(size--){
                int i = q.front().first ; 
                int j = q.front().second ; 
                q.pop() ; 

                dist[i][j] = level ;
                maxi = max(maxi ,level) ; 
                for(vector<int> &d : dir){
                    int nx = i + d[0] ; 
                    int ny = j + d[1] ;

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] )
                        continue ;

                    q.push({nx , ny}) ; 
                    vis[nx][ny]  = 1 ;   
                }
            }
            level++ ;
        }

        int l = 0 ; 
        int r = maxi ;
        int res = 0 ;
        while(l <= r){
            int mid = l + (r - l) / 2 ; 
            if(check(dist , mid)){
                res = mid ; 
                l = mid + 1 ;
            }
            else
                r = mid - 1 ;
        }
        return res ;
    }
};
