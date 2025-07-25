class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        int n = arr.size();
        int maxi = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int ele = arr[i];
            sum += ele;

            if (sum % k == 0) {
                maxi = max(maxi, i + 1);
            }

            int rem = sum % k;
            if (rem < 0) {
                rem += k;
            }

            if (mpp.find(rem) != mpp.end()) {
                int len = i - mpp[rem];
                maxi = max(maxi, len);
            }

            if (mpp.find(rem) == mpp.end()) {
                mpp[rem] = i;
            }
        }
        return maxi;
    }
};
