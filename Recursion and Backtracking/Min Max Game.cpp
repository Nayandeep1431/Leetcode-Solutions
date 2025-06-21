class Solution {
public:
    int solve(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int n = nums.size();
        vector<int> arr;
        bool mini = true;

        for (int i = 0; i < n; i += 2) {
            if (mini) {
                arr.push_back(min(nums[i], nums[i + 1]));
            } else {
                arr.push_back(max(nums[i], nums[i + 1]));
            }
            mini ^= 1; 
        }

        return solve(arr);
    }

    int minMaxGame(vector<int>& nums) {
        return solve(nums);
    }
};
