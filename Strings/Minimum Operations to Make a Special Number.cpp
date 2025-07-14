class Solution {
public:
    bool check(string s) {
        return s == "00" || s == "25" || s == "50" || s == "75";
    }

    int minimumOperations(string num) {
        int n = num.size();
        int mini = n;
        bool zero = false;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0')
                zero = true;
            for (int j = i + 1; j < n; j++) {
                string s = "";
                s += num[i];
                s += num[j];

                if (check(s))
                    mini = min(mini, n - i - 2);
            }
        }

        if (mini == n && zero)
            return n - 1;

        return mini;
    }
};
