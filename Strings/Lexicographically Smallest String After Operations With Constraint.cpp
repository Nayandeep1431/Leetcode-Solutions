class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';         
            int back = ch;               
            int forward = 26 - ch;      
            int mini = min(back , forward) ;
            if (mini <= k) {
                ans.push_back('a');
                k -= mini;
            } else {
                ans.push_back(s[i] - k); 
                k = 0;
            }
        }

        return ans;
    }
};
