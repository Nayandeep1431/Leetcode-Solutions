
class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int deletions = 0;

        for (int i = 1; i < 26; i++)
        {
            while (freq[i] != 0 && freq[i] >= freq[i - 1])
            {
                freq[i]--;
                deletions++;
            }
        }

        return deletions;
    }
};
