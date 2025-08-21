class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    dp[i][j] = (j == 0 ? 0 : dp[i][j-1]) + 1;
                }
            }
        }
        
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j < m ; j++){
                cout<<dp[i][j]<< " ";
            }
            cout<<endl ;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    int minWidth = dp[i][j];
                    for(int k = i; k < n && mat[k][j] == 1; k++) {
                        minWidth = min(minWidth, dp[k][j]);
                        ans += minWidth;
                    }
                }
            }
        }
        
        return ans;
    }
};
