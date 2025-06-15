class Solution {
public:
    string convert(string s, char ind, char val) {
        string t = s;
        for (int i = 0; i < s.length(); i++) {
            if (t[i] == ind)
                t[i] = val;
        }
        return t;
    }

    int maxDiff(int num) {
        string s = to_string(num);
        char first = 0;
        int n = s.length();

        // Fix: Find first non-'9' digit to replace for max
        for (int i = 0; i < n; ++i) {
            if (s[i] != '9') {
                first = s[i];
                break;
            }
        }

        string maxi;
        if (first)
            maxi = convert(s, first, '9');
        else
            maxi = s; 

        char mi = s[0];
        bool mm = false;
        string mini;

        if (mi != '1') {
            mini = convert(s, mi, '1');
        } else {
            for (int i = 1; i < n; i++) {
                if (s[i] != '0' && s[i] != '1') {
                    mi = s[i];
                    mm = true;
                    break;
                }
            }

            if (mm)
                mini = convert(s, mi, '0');
            else
                mini = s; // nothing to replace
        }

        int ans = stoi(maxi) - stoi(mini);
        return ans;
    }
};
