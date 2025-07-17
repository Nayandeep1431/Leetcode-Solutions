class Solution {

public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<vector<int>> dp(n , vector<int> (k , 0)) ;
        int maxi = 0 ;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< i ; j++){
                int val = (nums[i] + nums[j]) % k ;
                dp[i][val] = max(dp[i][val] , 1 + dp[j][val]) ;
                maxi = max(maxi , dp[i][val]) ;
            }
        }
        return maxi+1 ;
    }
};
