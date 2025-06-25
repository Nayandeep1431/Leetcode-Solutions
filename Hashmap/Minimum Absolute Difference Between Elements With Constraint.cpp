class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> st;
        int n = nums.size();
        int mini = INT_MAX;

        for (int i = x; i < n; i++) {
            st.insert(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            if (!st.empty()) {
                auto it = st.lower_bound(ele);
                if (it != st.end()) {
                    mini = min(mini, abs(ele - *it));
                }
                if (it != st.begin()) {
                    --it;
                    mini = min(mini, abs(ele - *it));
                }
            }

            if (i + x < n) {
                st.erase(st.find(nums[i + x])); // erase only one occurrence
            }

            if (i - x >= 0) {
                st.insert(nums[i - x]);
            }
        }

        return mini;
    }
};
