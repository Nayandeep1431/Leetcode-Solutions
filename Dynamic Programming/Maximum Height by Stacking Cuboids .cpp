class Solution {
    bool check(vector<int> &a , vector<int> &b){
        return a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2];
    }

    int solve(vector<vector<int>> &arr){
        int n = arr.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

        for(int i = n-1; i >= 0; i--){
            for(int prev = i-1; prev >= -1; prev--){
                int notTake = dp[i+1][prev+1];
                int take = 0;
                if(prev == -1 || check(arr[i], arr[prev]))
                    take = arr[i][2] + dp[i+1][i+1];  

                dp[i][prev+1] = max(take, notTake); 
            }
        }
        return dp[0][0];
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &it : cuboids){
            sort(it.begin(), it.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids);
    }
};
