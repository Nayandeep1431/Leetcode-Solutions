class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ; 
       if(n <= 1)
        return n ; 

        unordered_set<int> st ; 
        for(int i =0 ; i< n-1 ; i++){
            for(int j = i ; j< n ; j++)
                st.insert(nums[i] ^ nums[j]) ; 
        }
        unordered_set<int> s ; 
        for(auto it : st){
            for(int i =0 ; i< n ; i++){
                s.insert(nums[i] ^ it) ;
            }
        }
        return s.size() ; 
    }
};
