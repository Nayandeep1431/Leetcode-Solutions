class Solution {
public:
    string removeDuplicateLetters(string s) {
      int n = s.length() ; 
      unordered_map<char , int> mpp ; 
      for(char ch : s)
        mpp[ch]++ ; 

      stack<char> st ;
      vector<int> vis(26 , 0) ; 
      for(char ch : s){
        mpp[ch]-- ; 

        if(vis[ch - 'a'])
            continue ;
        while(!st.empty() && st.top() > ch && mpp[st.top()] > 0){
            vis[st.top() - 'a'] = false ;
            st.pop() ; 
        }
        st.push(ch) ; 
        vis[ch - 'a'] = true ;     
      }  
      string ans = "" ; 
      while(!st.empty()){
        ans = st.top() + ans ; 
        st.pop() ; 
      }
      return ans ;
    }
};
