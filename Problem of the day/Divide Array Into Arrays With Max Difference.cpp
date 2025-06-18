class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        int sub = n / 3 ;

        sort(nums.begin() , nums.end()) ;
        vector<vector<int>> ans ;
        for(int i = 0 ; i< n ; i+= 3){
            int ele = nums[i] ;
            int last = nums[i+ 2] ;
            if(last - ele > k)
                return {} ;
            else{
                vector<int> temp ;
                for(int j =i ; j< i + 3 ; j++){
                    temp.push_back(nums[j]) ;
                }
                ans.push_back(temp) ;
            }    
        }
        return ans ;
    }
};
