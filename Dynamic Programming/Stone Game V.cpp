class Solution {
public:
    int n;
    int dp[501][501] ; 
    int solve(int start, int end, vector<int>& arr, vector<int>& prefix) {
        if (start > end || start >= n)
            return 0;

        if (start == end)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end] ; 
        int maxi = INT_MIN;

        for (int i = start; i < end; i++) {
            int sum = 0;

            int left = prefix[i] - (start > 0 ? prefix[start - 1] : 0);
            int right = prefix[end] - prefix[i];

            if (left > right)
                sum = right + solve(i + 1, end, arr, prefix);
            else if (right > left)
                sum = left + solve(start, i, arr, prefix);
            else
                sum = left + max(solve(start, i, arr, prefix),
                                 solve(i + 1, end, arr, prefix));

            maxi = max(maxi, sum);
        }

        return dp[start][end] = maxi;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        vector<int> prefix(n);
        prefix[0] = stoneValue[0];

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + stoneValue[i];

        memset(dp , -1 , sizeof(dp)) ; 
        return solve(0, n - 1, stoneValue, prefix);
    }
};
