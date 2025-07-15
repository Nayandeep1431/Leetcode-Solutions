class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size() ;
        int tbd = n - k ;

        stack<int> st ;
        for(int i =0 ; i< n ; i++){
            int ele = nums[i] ;
            while (!st.empty() && tbd > 0 && st.top() > ele) {
                st.pop();
                tbd--;
            }
            st.push(ele) ;
        }
        while(st.size() > k)
            st.pop() ;

        vector<int> ans ;
        while(!st.empty()){
            ans.push_back(st.top()) ;
            st.pop() ;
        }    
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};
