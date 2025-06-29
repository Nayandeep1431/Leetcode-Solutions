class Solution {
public:
    int solve(string s, char ch, int k) {
        int l = 0, r = 0;
        int cnt = k;
        int maxi = 0; 
        int n = s.length();

        while (r < n) {
            if (s[r] != ch)
                cnt--;

            while (cnt < 0) {
                if (s[l] != ch)
                    cnt++;
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = solve(answerKey, 'T', k);
        int f = solve(answerKey, 'F', k);
        return max(t, f);
    }
};
