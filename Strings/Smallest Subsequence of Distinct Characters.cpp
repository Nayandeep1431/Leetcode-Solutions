class Solution {
public:
    string smallestSubsequence(string s) {

        unordered_map<char, int> mpp;
        vector<int> vis(26, 0);
        
        for (char it : s) {
            mpp[it]++;
        }

        stack<char> st;

        for (char ch : s) {
            mpp[ch]--;

            if (vis[ch - 'a'])
                continue;

            while (!st.empty() && st.top() > ch && mpp[st.top()] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            vis[ch - 'a'] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

