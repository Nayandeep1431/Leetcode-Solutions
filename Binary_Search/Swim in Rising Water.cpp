class Solution {
public:
    bool possible(vector<vector<int>> &grid , int mid){
        int n = grid.size() ; 
        vector<vector<int>> vis(n, vector<int> (n , 0)) ; 
        queue<pair<int ,int>> q ; 
        q.push({0 , 0}) ; 
        int dr[4] = {-1 , 1 ,0 ,0} ; 
        int dc[4] = {0 , 0 , 1 , -1} ; 
        if(grid[0][0] > mid)
            return false ;
        while(!q.empty()){
            auto [i , j] = q.front() ; 
            q.pop() ; 
            vis[i][j] = 1 ;
            if(i == n-1 && j == n-1)
                return true ;

            for(int k =0 ; k< 4; k++){
                int nx = i + dr[k] ; 
                int ny = j + dc[k] ; 

                if(nx >= 0 && ny >= 0 && ny < n && nx < n && !vis[nx][ny] && grid[nx][ny] <= mid){
                    vis[nx][ny] = 1 ; 
                    q.push({nx , ny}) ; 
                }
            }    
        }
        return false ;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int l = 0 , r = n * n ; 
        int res = n*n ; 
        while(l <= r){
            int mid = l + (r - l ) / 2 ; 
            if(possible(grid , mid)){
                res = mid ; 
                r = mid - 1 ;
            }
            else
                l = mid + 1 ;
        }
        return res ;
    }
};
