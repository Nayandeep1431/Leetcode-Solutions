class Solution {
public:
    typedef long long ll;
    
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        ll required = 1;
        ll presum = 0;
        int cnt = 0;
        int i = 0;
        
        while (presum < n) {
            if (i < m && nums[i] <= required) {
                presum += nums[i];
                required = presum + 1;
                i++;
            } else {
                presum += required;
                required = presum + 1;
                cnt++;
            }
        }
        
        return cnt;
    }
};
