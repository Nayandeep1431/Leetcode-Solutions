class Solution {
public:
    typedef long long ll;

    int myAtoi(string s) {
        int n = s.length();
        bool start = false;
        ll ans = 0;
        bool neg = false;
        int i = 0;
        bool sign = false;

        while (i < n && s[i] == ' ')
            i++;

        for (; i < n; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                start = true;
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && ch - '0' > INT_MAX % 10)) {
                    return neg ? INT_MIN : INT_MAX;
                }
                ans = ans * 10 + (ch - '0');
            } else {
                if (ch == '-' && !start && !sign) {
                    neg = true;
                    sign = true;
                } else if (ch == '+' && !start && !sign) {
                    sign = true;
                } else {
                    break;
                }
            }
        }

        if (neg)
            ans = -ans;

        if (ans > INT_MAX)
            ans = INT_MAX;

        if (ans < INT_MIN)
            ans = INT_MIN;

        return ans;
    }
};
