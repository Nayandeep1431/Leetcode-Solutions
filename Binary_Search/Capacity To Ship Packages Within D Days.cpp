class Solution {
    typedef long long ll;

    int solve(vector<int> &arr, ll mid) {
        int days = 1;
        int load = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (load + arr[i] <= mid)
                load += arr[i];
            else {
                load = arr[i];
                days++;
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        ll low = *max_element(weights.begin(), weights.end());
        ll sum = accumulate(weights.begin(), weights.end(), 0LL); // Use 0LL for long long
        ll high = sum;

        while (low <= high) {
            ll mid = low + (high - low) / 2; 
            int d = solve(weights, mid);
            if (d <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
