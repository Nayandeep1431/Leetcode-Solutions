
class Solution {
    vector<int> lis(const vector<int> &arr, int n){
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i])
                    dp[i] = 1 + dp[prev];
            }
        }
        return dp;
    }
    
    vector<int> lds(const vector<int> &arr, int n){
        vector<int> dp(n, 1);
        for(int i = n - 1; i >= 0; i--){
            for(int prev = n - 1; prev > i; prev--){
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev];
            }
        }
        return dp;
    }

public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc = lis(nums, n);
        vector<int> dec = lds(nums, n);

        // Check for strictly increasing
        bool strictlyIncreasing = true;
        for(int i = 0; i < n; i++) {
            if(dec[i] != 1) {
                strictlyIncreasing = false;
                break;
            }
        }

        // Check for strictly decreasing
        bool strictlyDecreasing = true;
        for(int i = 0; i < n; i++) {
            if(inc[i] != 1) {
                strictlyDecreasing = false;
                break;
            }
        }

        if(strictlyIncreasing || strictlyDecreasing)
            return 0;

        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(inc[i]!=1 && dec[i]!=1)
             maxi = max(maxi,inc[i]+dec[i]-1);
        }
        return maxi;
    }
};

