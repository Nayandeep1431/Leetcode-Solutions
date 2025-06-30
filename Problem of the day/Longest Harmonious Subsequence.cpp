class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, maxi = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > 1) {
                l++;
            }
            if (nums[r] - nums[l] == 1) {
                maxi = max(maxi, r - l + 1);
            }
        }
        return maxi;
    }
};
