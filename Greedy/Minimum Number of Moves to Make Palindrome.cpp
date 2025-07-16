class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l = 0, r = s.size() - 1;
        int res = 0;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                int k = r;
                while (k > l && s[k] != s[l]) k--;
                if (k == l) {
                    swap(s[l], s[l+1]);
                    res++;
                } else {
                    for (int i = k; i < r; i++) {
                        swap(s[i], s[i+1]);
                        res++;
                    }
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
