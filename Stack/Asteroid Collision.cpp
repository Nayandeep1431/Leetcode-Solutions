class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size() ; 
        stack<int> st ;
        for(int i =0; i< n ; i++){
            int val = arr[i] ; 
            while(!st.empty() && val < 0 && st.top() > 0){
                int sum = val + st.top() ; 
                if(sum < 0)
                    st.pop() ; 
                else if(sum > 0)
                    val = 0 ; 
                else{
                    val = 0 ; 
                    st.pop() ; 
                }        
            }
            if(val != 0)
                st.push(val) ; 
        }
         n = st.size() ; 
        vector<int> ans(n) ; 
        if(st.empty())
            return ans ;
        while(!st.empty()){
            ans[n-1] = st.top() ;
            st.pop() ;
            n-- ; 
        }
        return ans ;
    }
};
