class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size() ;
        stack<int> st ;
        vector<int> ans(n) ;
        for(int i =n-1 ; i>=0 ; i--){
            int cnt = 0 ;
            while(!st.empty() && st.top() < arr[i]){
                cnt++ ;
                st.pop() ;
            }
            if(!st.empty() && st.top() > arr[i])
                cnt += 1 ;

            ans[i] = cnt ;   
            st.push(arr[i]) ;  
        }
        return ans ;
    }
};


