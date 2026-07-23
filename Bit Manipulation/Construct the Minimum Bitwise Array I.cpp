class Solution {
public:
    int solve(int n){
        int ans =  - 1 ; 
        for(int i =1 ; i< n ; i++){
            if((i | (i+1)) == n){
                ans = i ; 
                break ; 
            }
        }
        return ans ;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> ans(n) ; 
        for(int i =0 ; i < n ; i++){
            ans[i] = solve(nums[i]) ; 
        }
        return ans ;
    }
};
