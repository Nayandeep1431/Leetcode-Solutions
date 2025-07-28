class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> st;
        string numStr = "";
        
        for (char ch : word) {
            if (isdigit(ch)) {
                numStr += ch;
            }
            else if (!numStr.empty()) {
                size_t i = 0;
                while (i < numStr.size() - 1 && numStr[i] == '0') {
                    i++;
                }
                st.insert(numStr.substr(i));
                numStr.clear();
            }
        }
        
        if (!numStr.empty()) {
            size_t i = 0;
            while (i < numStr.size() - 1 && numStr[i] == '0') {
                i++;
            }
            st.insert(numStr.substr(i));
        }
        
        return st.size();
    }
};
