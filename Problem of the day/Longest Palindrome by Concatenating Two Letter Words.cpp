class Solution {
    bool check(string s) {
        return s[0] == s[1];
    }
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for (auto& w : words) mpp[w]++;
        
        int len = 0;
        bool centerUsed = false;
        
        for (auto& [s, cnt] : mpp) {
            if (s[0] == s[1]) {
                len += (cnt / 2) * 4;
                if (cnt % 2) centerUsed = true;
            } else {
                string rev = s;
                reverse(rev.begin(), rev.end());
                if (mpp.count(rev)) {
                    int pairs = min(cnt, mpp[rev]);
                    len += pairs * 4;
                    mpp[rev] = 0;
                    mpp[s] = 0;
                }
            }
        }
        
        if (centerUsed) len += 2;
        return len;
    }
};
