class Solution {
    typedef long long ll;
public:
    ll findCount(vector<int>& nums1, vector<int>& nums2, ll mid) {
        int n = nums1.size();
        int m = nums2.size();

        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] >= 0) {
                int l = 0, r = m - 1, pos = -1;
                while (l <= r) {
                    int mi = (l + r) / 2;
                    ll pro = 1LL * nums1[i] * nums2[mi];
                    if (pro <= mid) {
                        pos = mi;
                        l = mi + 1;
                    } else {
                        r = mi - 1;
                    }
                }
                cnt += (pos + 1);
            } else {
                int l = 0, r = m - 1, pos = m;
                while (l <= r) {
                    int mi = (l + r) / 2;
                    ll pro = 1LL * nums1[i] * nums2[mi];
                    if (pro <= mid) {
                        pos = mi;
                        r = mi - 1;
                    } else {
                        l = mi + 1;
                    }
                }
                cnt += (m - pos);
            }
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        ll l = -1e10, r = 1e10;
        ll ans = 0;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll cnt = findCount(nums1, nums2, mid);
            if (cnt >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
