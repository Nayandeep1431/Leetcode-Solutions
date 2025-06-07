class Solution {
public:
    string add(string s1, string s2) {
        int i = s1.length() - 1;
        int j = s2.length() - 1;

        string output = "";
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';

            output.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(output.begin(), output.end());
        return output;  
    }

    bool check(string &s, int start, int len1, int len2, int n) {
        string s1 = s.substr(start, len1);
        string s2 = s.substr(start + len1, len2);

        string s3 = add(s1, s2);
        int len3 = s3.length();

        if (start + len1 + len2 + len3 > n)
            return false;

        if (s3 == s.substr(start + len1 + len2, len3)) {
            if (start + len1 + len2 + len3 == n)
                return true;

            return check(s, start + len1, len2, len3, n);
        }
        return false;
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {             
            for (int j = 1; i + j < n; j++) {
                if (check(s, 0, i, j, n))           
                    return true;
            }
        }
        return false;
    }
};
