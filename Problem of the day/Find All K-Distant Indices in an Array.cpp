class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size() ;
        vector<int> arr(n , 0) ;
        for(int i = 0 ; i< n ; i++){
            if(nums[i] != key)
                continue ;
            for(int j = 0 ; j< n ; j++){

                if(abs(i - j) <= k)
                    arr[j] = 1;    
            }    
        }
        vector<int> ans ;
        for(int i =0 ; i< n ; i++){
            if(arr[i] == 1)
                ans.push_back(i) ;
        }
        return ans ;
    }
};
