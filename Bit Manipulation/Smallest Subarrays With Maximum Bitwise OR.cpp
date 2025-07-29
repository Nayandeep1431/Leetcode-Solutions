class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeen(32, -1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    lastSeen[bit] = i;
                }
            }
            int maxReach = i;
            for (int bit = 0; bit < 32; bit++) {
                if (lastSeen[bit] != -1) {
                    maxReach = max(maxReach, lastSeen[bit]);
                }
            }
            ans[i] = maxReach - i + 1;
        }

        return ans;
    }
};
