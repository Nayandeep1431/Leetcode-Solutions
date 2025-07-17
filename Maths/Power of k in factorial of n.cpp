class Solution {
public:
    unordered_map<int, int> mpp;  
    unordered_map<int, int> mpp2; 

    void primeFactors(int k) {
        while (k % 2 == 0) {
            mpp2[2]++;
            k /= 2;
        }
        for (int i = 3; i * i <= k; i += 2) {
            while (k % i == 0) {
                mpp2[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            mpp2[k]++;
        }
    }


    void countPrimeFactorsInFactorial(int n) {
        for (auto it : mpp2) {
            int p = it.first;
            int count = 0;
            int x = n;
            while (x) {
                count += x / p;
                x /= p;
            }
            mpp[p] = count;
        }
    }

    int maxKPower(int n, int k) {
        primeFactors(k);
        countPrimeFactorsInFactorial(n);

        int mini = INT_MAX;
        for (auto it : mpp2) {
            int prime = it.first;
            int freqInK = it.second;
            int freqInFact = mpp[prime];

            int maxPower = freqInFact / freqInK;
            mini = min(mini, maxPower);
        }

        return mini;
    }
};
