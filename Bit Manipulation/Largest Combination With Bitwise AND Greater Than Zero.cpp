class Solution {
public:
    int largestCombination(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(32, 0);
        for (int i = 0; i < n; i++) {
            int ele = arr[i];
            for (int j = 0; j < 32; j++) {
                if (ele & (1 << j)) {
                    cnt[j]++;
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < 32; i++) {
            maxi = max(maxi, cnt[i]);
        }
        return maxi;
    }
};
