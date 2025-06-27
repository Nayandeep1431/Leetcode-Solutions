class Solution {
    int count(string s, string temp) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i <= n - temp.size(); i++) {
            string sub = s.substr(i, temp.length());
            if (sub == temp)
                cnt++;
        }
        return cnt;
    }

public:
    int maximumLength(string s) { 
        int n = s.length();
        int maxi = 0;
        string prev = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (!prev.empty() && prev.back() == ch)
                prev += ch;
            else
                prev = ch;

            if (count(s, prev) >= 3)
                maxi = max(maxi, (int)prev.size());
        }
        return (maxi == 0) ? -1 : maxi;
    }
};
