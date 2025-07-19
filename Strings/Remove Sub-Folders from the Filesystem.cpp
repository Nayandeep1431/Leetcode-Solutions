class Solution {
public:
    bool check(string s , unordered_set<string> &st){
        int n = s.length();
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '/'){
                string sub = s.substr(0 , i);
                if(st.find(sub) != st.end())
                    return true;
            }
        }
        return false;
    }

    static bool cmp(const string &a, const string &b) {
        return a.size() < b.size();
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        sort(folder.begin(), folder.end(), cmp);
        vector<string> ans;

        for(int i = 0; i < folder.size(); i++) {
            if(st.empty() || check(folder[i], st) == false) {
                ans.push_back(folder[i]);
                st.insert(folder[i]);  
            }
        }

        return ans;
    }
};
