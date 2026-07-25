class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n = s.length() ; 
        if((n & (n-1)) == 0)
            k = k / 2 ; 
        else
            k = k* 2 ; 
        
        if(k > n)
            return "-1" ; 
            
        stack<char> st ; 
        for(int i =0 ; i< n ; i++){
            while(!st.empty() && k > 0 &&  st.top() > s[i]){
                st.pop() ; 
                k-- ;
            }    
            st.push(s[i]) ;     
        }
        while(!st.empty() && k > 0){
            st.pop() ; 
            k-- ; 
        }
        
        if(st.empty())
            return "-1" ; 
        
        string ans = "" ; 
        while(!st.empty()){
            ans = st.top() + ans ; 
            st.pop() ; 
        }
        return ans ; 
    }
};
