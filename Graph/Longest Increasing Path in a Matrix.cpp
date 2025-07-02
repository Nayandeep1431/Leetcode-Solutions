class Solution {
public:
    int dfs(int i , int j , vector<vector<int>> &grid , int dx[] , int dy[] , vector<vector<int>> &dp){

        if(dp[i][j] != -1)
            return dp[i][j] ;

        int maxi = 1 ;
        for(int k =0 ; k < 4 ; k++){
            int nx = i + dx[k] ;
            int ny = j + dy[k] ;

            if(nx >=0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] > grid[i][j])
                maxi = max(maxi , 1 + dfs(nx , ny , grid , dx , dy , dp)) ;
        }
        return dp[i][j] = maxi ;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        int maxi = 1 ;
        vector<vector<int>> dp(n , vector<int> (m , -1)) ;
        int dx[] = {-1 ,1 , 0 ,0} ;
        int dy[] = {0 , 0 , 1 , -1} ;
        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j< m ; j++){
                int val = dfs(i , j , matrix , dx , dy , dp) ;
                maxi = max(maxi , val) ;
            }
        }
        return maxi ;
    }
};
