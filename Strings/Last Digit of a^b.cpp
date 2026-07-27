class Solution {
public:
    int value(string b) {
        int n = b.size();
        return (b[n - 2] - '0') * 10 + (b[n - 1] - '0');
    }

    int getLastDigit(string& a, string& b) {

        int n = a.size();
        int m = b.size();

        if (m == 1 && b[0] == '0')
            return 1;

        if (n == 1 && a[0] == '0')
            return 0;

        int val = (m == 1) ? (b[0] - '0') : value(b);

        int last = a[n - 1] - '0';   

        int rem = val % 4;
        if (rem == 0)
            rem = 4;

        int num = last;

        for (int i = 1; i < rem; i++) {
            num = (num * last) % 10;
        }

        return num;
    }
};
