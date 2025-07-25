class Solution {
public:
    int maxSum(vector<int>& nums) {
       int n = nums.size() ;
       unordered_set<int> st ;
       int neg = INT_MIN ;
       for(int i =0 ; i< n ; i++){
            int ele = nums[i] ;
            if(ele > 0){
                st.insert(ele) ;
            }
            else{
                neg = max(neg , ele) ;
            }
       }
       if(st.empty())
        return neg ;

       int ans  =0 ;
       for(auto it : st){
        ans += it ;
       } 
       return ans ;
    }
};
