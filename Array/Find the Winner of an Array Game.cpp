class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (k >= n) return *max_element(arr.begin(), arr.end());

        int i = 0, j = 1, cnt = 0, prev = -1;

        while (j < n) {
            if (arr[i] > arr[j]) {
                if (prev == arr[i]) {
                    cnt++;
                } else {
                    prev = arr[i];
                    cnt = 1;
                }
                j++;
            } else {
                if (prev == arr[j]) {
                    cnt++;
                } else {
                    prev = arr[j];
                    cnt = 1;
                }
                i = j;
                j++;
            }

            if (cnt == k) return prev;
        }

        return prev;
    }
};
