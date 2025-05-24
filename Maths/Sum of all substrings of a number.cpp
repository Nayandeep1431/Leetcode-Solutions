class Solution {
  public:
    int sumSubstrings(string s) {
        int n = s.length();
        long long result = 0;
        long long prev = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int num = s[i] - '0';
            prev = (prev * 10 + num * 1LL * (i + 1)) ;
            result = (result + prev) ;
        }

        return result;
    }
};
