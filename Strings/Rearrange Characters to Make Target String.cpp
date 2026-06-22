class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> freqS, freqT;

        for (char ch : s)
            freqS[ch]++;

        for (char ch : target)
            freqT[ch]++;

        int ans = INT_MAX;

        for (auto &it : freqT) {
            char ch = it.first;
            int need = it.second;
            ans = min(ans, freqS[ch] / need);
        }

        return ans;
    }
};
