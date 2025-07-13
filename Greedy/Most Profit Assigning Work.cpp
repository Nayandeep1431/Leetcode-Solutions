class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({difficulty[i], profit[i]});
        }

        sort(arr.begin(), arr.end());
        sort(worker.begin(), worker.end());

        int i = 0, j = 0, maxi = 0, total = 0;

        for (int w : worker) {
            while (i < n && arr[i].first <= w) {
                maxi = max(maxi, arr[i].second);
                i++;
            }
            total += maxi;
        }

        return total;
    }
};
