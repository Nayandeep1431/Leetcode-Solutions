class Solution {
    typedef long long ll;
public:
    int bs(int ind, vector<int>& nums, int k, const vector<ll>& pre) {
        ll target = nums[ind];
        int l = 0, r = ind;
        int maxi = ind;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            ll windowSum = (ll)(ind - mid + 1) * target;
            ll currSum = pre[ind] - (mid > 0 ? pre[mid - 1] : 0);
            ll ops = windowSum - currSum;

            if (ops > k)
                l = mid + 1;
            else {
                maxi = mid;
                r = mid - 1;
            }
        }

        return ind - maxi + 1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<ll> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, bs(i, nums, k, prefix));
        }

        return res;
    }
};
