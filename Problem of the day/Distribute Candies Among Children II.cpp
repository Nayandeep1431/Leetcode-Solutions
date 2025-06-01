class Solution {
public:
    typedef long long ll;

    long long distributeCandies(int n, int limit) {
        ll ways = 0;
        ll minChild1 = max(0, n - 2 * limit);
        ll maxChild1 = min((ll)n, (ll)limit);

        for (ll i = minChild1; i <= maxChild1; i++) {
            int newN = n - i;
            int minChild2 = max(0, newN - limit);
            int maxChild2 = min(newN, limit);
            ll w = maxChild2 - minChild2 + 1;
            ways += w;
        }

        return ways;
    }
};
