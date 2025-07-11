class Solution {
public:
    // Recursion
    int solve(int start ,int end , int ind , vector<int> &nums , vector<int> &arr){
        if(ind >= arr.size())
            return 0 ;

          int aagese = arr[ind] * nums[start] + solve(start+1 , end , ind+1 , nums , arr) ;
          int pichese = arr[ind] * nums[end] + solve(start , end-1 , ind + 1 , nums , arr) ;

          return max(aagese , pichese) ;  
    }

    // Memoization
int solveMem(int start, int end, vector<int>& nums, vector<int>& arr, unordered_map<string, int>& dp) {
    int ind = nums.size() - (end - start + 1);
    if (ind >= arr.size())
        return 0;

    string key = to_string(start) + "#" + to_string(end);
    if (dp.count(key))
        return dp[key];

    int front = arr[ind] * nums[start] + solveMem(start + 1, end, nums, arr, dp);
    int back = arr[ind] * nums[end] + solveMem(start, end - 1, nums, arr, dp);

    return dp[key] = max(front, back);
}
    // Tabulation
    int solveTab(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        
        for(int i = m-1; i>=0; i--){
            for(int left = i; left >= 0; left--) {
                int mult = multipliers[i];
                int right = n - 1 - (i - left);
                dp[i][left] = max(mult * nums[left] + dp[i + 1][left + 1], 
                                       mult * nums[right] + dp[i + 1][left]);
            }
        }
        return dp[0][0];
    }

    int maximumScore(vector<int>& nums, vector<int>& arr) {
        int n = nums.size() ;
        int m = arr.size() ;
        // return solve(0, n-1 , 0 , nums , multipliers) ;

    unordered_map<string , int> dp ;
    return solveMem(0, n - 1, nums, arr, dp);
}

};
