class Solution {
public:
    int longestSubarray(vector<int>& arr , int limit) {
        int n = arr.size();
        int l = 0, r = 0;
        int maxi = 0;
        multiset<int> ms;

        while (r < n) {
            ms.insert(arr[r]);

            while (*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(arr[l]));
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};
