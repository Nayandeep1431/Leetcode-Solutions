class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i*i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int countNumbers(int n) {
        vector<int> primes;
        for (int i = 2; i*i <= n; i++) {
            if (isPrime(i)) primes.push_back(i);
        }

        int cnt = 0;

        // Case 1: p^8
        for (int p : primes) {
            long long val = 1;
            for (int i = 0; i < 8; i++) val *= p;
            if (val <= n) cnt++;
            else break;
        }

        // Case 2: p^2 * q^2
        int sz = primes.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i+1; j < sz; j++) {
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (val <= n) cnt++;
                else break;
            }
        }

        return cnt;
    }
};
