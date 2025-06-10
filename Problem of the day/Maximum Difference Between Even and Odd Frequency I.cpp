class Solution {
public:
    int maxDifference(string s) {
        vector<int> c(26, 0);
        for (char ch : s) {
            c[ch - 'a']++;
        }

        int oddFreq = INT_MIN;
        int evenFreq = INT_MAX;

        for (int freq : c) {
            if (freq == 0) continue;

            if (freq % 2 == 1) {
                oddFreq = max(oddFreq, freq);
            } else {
                evenFreq = min(evenFreq, freq);
            }
        }

        if (oddFreq == INT_MIN || evenFreq == INT_MAX)
            return -1; 

        return oddFreq - evenFreq;
    }
};
