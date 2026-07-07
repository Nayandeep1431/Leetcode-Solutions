class Solution {
public:
    int n , m ;
    int dp[100][100][205] ; 

    bool dfs(int i , int j , int k , vector<vector<char>> &grid){
        if(i >= n || j >=m)
            return 0 ; 

        if(grid[i][j] == ')')
            k-- ; 
        else
            k++ ;

        if(i == n-1 && j == m-1)
            return k == 0 ;

        if(k < 0)
            return 0 ; 

        if(dp[i][j][k] != -1)
            return dp[i][j][k] ; 

        return dp[i][j][k] =  dfs(i+1 , j , k , grid) | dfs(i , j+1 , k ,grid) ;                     
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size(); 
        m = grid[0].size() ; 
        memset(dp, -1, sizeof(dp));
        return dfs(0 , 0 , 0 , grid) ; 
    }
};
