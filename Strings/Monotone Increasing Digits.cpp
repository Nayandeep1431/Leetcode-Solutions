class Solution {
public:
    string remove(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == '0')
            i++;
        string res = s.substr(i);
        return res.empty() ? "0" : res;
    }

    string solve(string s) {
        int n = s.length();
        for (int i = n - 1; i > 0; i--) {
            if (s[i] < s[i - 1]) {
                s[i - 1]--;
                for (int j = i; j < n; j++) {
                    s[j] = '9';
                }
            }
        }
        return s;
    }

    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        string modified = solve(s);
        modified = remove(modified);
        return stoi(modified);
    }
};
