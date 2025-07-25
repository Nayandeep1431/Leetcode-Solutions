class Solution {
  public:
    string maxSubseq(string& s, int k) {
        stack<int> st;
        for(auto ch: s){
            while (!st.empty() and st.top()<ch and k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while (!st.empty() and k>0){
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty()){
            ans = char(st.top()) + ans ;
            st.pop();
        }
        return ans;
    }
};
