class Solution {
  public:
int solve(int rem, int cur) {
    if (rem == 0) return 1;
    if (rem < 0) return 0;

    return solve(rem - cur, cur + 1);
}

int getCount(int n) {
    int cnt = 0;

    for (int start = 1; start <= n / 2; start++)
        cnt += solve(n - start, start + 1);

    return cnt;
}
};
