class Solution {
public:
    using ll = long long;

    ll value(ll n) {
        return n * (n + 1) * (2 * n + 1) / 6;
    }

    int maxPeopleDefeated(int p) {
        int low = 0;
        int high = sqrt((long double)p) + 1;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (value(mid) <= (ll)p) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
