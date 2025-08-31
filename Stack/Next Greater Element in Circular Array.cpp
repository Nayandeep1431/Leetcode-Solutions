class Solution {
  public:
    vector<int> solve(vector<int> &arr, int m){
        int n = arr.size() ;
        vector<int> ans(n/2 , -1) ;
        stack<int> st ;
        for(int i = n-1 ; i>= 0 ; i--){
            int curr = arr[i] ;
            while(!st.empty() && st.top() <= curr)
                st.pop() ;
            
            if(i < m)
                ans[i] = (st.empty()) ? -1 : st.top() ;
            
            st.push(curr) ;    
        }
        return ans ;
    }
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n=arr.size();
       for(int i =0 ; i< n ; i++)
        arr.push_back(arr[i]) ;
        
        return solve(arr , n) ;
    }
};
