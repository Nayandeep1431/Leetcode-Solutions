class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = endTime.size();
        vector<int> free;
        free.push_back(startTime[0]);

        for (int i = 1; i < n; i++) {
            free.push_back(startTime[i] - endTime[i - 1]);
        }

        free.push_back(eventTime - endTime[n - 1]);

        n = free.size();  

        vector<int> right(n, 0), left(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], free[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], free[i - 1]);
        }

        int maxi = 0;
        for (int i = 1; i < n; i++) {
                int curr = endTime[i - 1] - startTime[i - 1];
                if (curr <= max(right[i], left[i - 1])) {
                    maxi = max(maxi, free[i - 1] + free[i] + curr);
                }

            maxi = max(maxi, free[i - 1] + free[i]);
        }

        return maxi;
    }
};
