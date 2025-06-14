typedef long long ll;

class Solution {
    bool check(const vector<int>& time, int totalTrips, ll mid) {
        ll trips = 0;
        for (int t : time) {
            trips += mid / t;
            if (trips >= totalTrips) return true;
        }
        return trips >= totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1, r = 1e14, res = -1;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(time, totalTrips, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
