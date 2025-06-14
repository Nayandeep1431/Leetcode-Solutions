class Solution {
    bool check(vector<int> &dist, int mid, double hr) {
        int n = dist.size();
        double total = 0;

        for (int i = 0; i < n - 1; i++) {
            total += ceil((double)(dist[i]) / (double)(mid));
        }
        total += (double)(dist[n - 1]) / (double)(mid);

        return total <= (double)(hr);
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;
        int res = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(dist, mid, hour)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
