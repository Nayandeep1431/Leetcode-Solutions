class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // sort by ending time
    }

    vector<vector<int>> maxDisjointInterval(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end(), comp);

        int end = -1;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i][0] > end) {
                ans.push_back(arr[i]);
                end = arr[i][1];
            }
        }

        return ans;
    }
};
