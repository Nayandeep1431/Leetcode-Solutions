class Solution {
public:
    void removeLeadingZeroes(string &s) {
        int i = 0;
        while (i < s.length() && s[i] == '0') {
            i++;
        }
        s = s.substr(i);
        if (s.empty()) s = "0";
    }

    string removeKdigits(string num, int k) {
        string s = "";

        for (char digit : num) {
            while (!s.empty() && k > 0 && s.back() > digit) {
                s.pop_back();
                k--;
            }
            s.push_back(digit);
        }

        while (k-- > 0 && !s.empty()) {
            s.pop_back();
        }

        removeLeadingZeroes(s);
        return s;
    }
};
