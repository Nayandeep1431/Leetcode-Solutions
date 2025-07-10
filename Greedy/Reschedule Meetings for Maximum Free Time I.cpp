class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> free;

        free.push_back(startTime[0]);

        for (int i = 1; i < n; i++) {
            free.push_back(startTime[i] - endTime[i - 1]);
        }

        free.push_back(eventTime - endTime[n - 1]);

        int i = 0, j = 0;
        int maxi = 0;
        int currSum = 0;

        while (j < free.size()) {
            currSum += free[j];

            if (j - i + 1 > k + 1) {
                currSum -= free[i];
                i++;
            }

            maxi = max(maxi, currSum);
            j++;  
        }

        return maxi;
    }
};
