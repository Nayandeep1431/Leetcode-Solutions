class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length() ;
        stack<int> st ; 
        for(int i =0 ; i< n ; i++){
            char ch = s[i] ; 
            if(ch == '(')
                st.push(-1) ; 
            else{
                if(st.top() == -1){
                    st.pop() ; 
                    st.push(1) ;
                }
                else{
                    int val = 0 ; 
                    while(st.top() != -1){
                        val += st.top() ; 
                        st.pop() ; 
                    }
                    st.pop() ;
                    st.push(2*val) ; 
                }
            }    
        }
        int ans = 0 ; 
        while(!st.empty()){
            ans += st.top() ; 
            st.pop() ; 
        }
        return ans ;
    }
};
