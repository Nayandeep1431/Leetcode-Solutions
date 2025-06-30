class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int i = 0, j = 0;
        int curr = 0;
        int maxi = 0;

        while (i < n) {
            curr += abs(s[i] - t[i]);
            while (curr > maxCost) {
                curr -= abs(s[j] - t[j]);
                j++;
            }
            maxi = max(maxi, i - j + 1);
            i++;
        }

        return maxi;
    }
};
