class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        if (m == 0) return vector<int>(word.length(), 0);
        if (word.empty()) return {};

        int n = word.length();
        vector<int> ans(n, 0);
        long long ele = 0;
        
        for (int i = 0; i < n; i++) {
            if (!isdigit(word[i])) return vector<int>(n, 0);
            
            int val = word[i] - '0';
            ele = (ele * 10 + val) % m;
            
            if (ele == 0) {
                ans[i] = 1;
            }
        }
        
        return ans;
    }
};
