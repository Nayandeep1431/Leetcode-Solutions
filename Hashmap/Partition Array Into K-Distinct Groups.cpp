class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(n % k != 0)
            return false ;

        int groups = n / k ;
        unordered_map<int , int> mpp ;
        for(int i =0 ; i< n ; i++){
            mpp[nums[i]]++ ;
        }   
        for(auto it : mpp){
            if(it.second > groups)
                return false ;
        }
        return true ;
    }
};
