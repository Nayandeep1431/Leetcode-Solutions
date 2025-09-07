class Solution {
public:
    typedef long long ll ;
    vector<int> pg(vector<int> &arr){
        int n = arr.size() ;
        stack<int> st ;
        vector<int> ans(n) ;
        for(int i =0 ; i< n ; i++){
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop() ;

            ans[i] = st.empty() ? -1 : st.top() ;
            st.push(i) ;    
        }
        return ans ;
    }

        vector<int> ng(vector<int> &arr){
        int n = arr.size() ;
        stack<int> st ;
        vector<int> ans(n) ;
        for(int i =n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop() ;

            ans[i] = st.empty() ? -1 : st.top() ;
            st.push(i) ;    
        }
        return ans ;
    }
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> next = ng(nums) ;
        vector<int> prev = pg(nums) ;

        ll cnt= 0 ;
        for(int i =0 ; i< n ; i++){
            if(next[i] == -1 || prev[i] == -1)
                continue ;

            cnt++ ;    
        }
        return cnt ;
    }
};
