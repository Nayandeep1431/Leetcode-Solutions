class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.length();
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;
            set<int> s;
            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0)
                    s.insert(freq[j]);
            }
            if (s.size() == 1)
                return true;
            freq[i]++;
        }
        return false;
    }
};
