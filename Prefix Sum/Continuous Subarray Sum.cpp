class Solution {
    typedef long long ll ;
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mpp ;
        int n = nums.size() ;

        ll sum = 0 ;
        mpp[0] = -1 ;
        for(int i =0 ; i< n ; i++){
            sum += nums[i] ;

            int rem = sum % k ;
            if(mpp.find(rem) != mpp.end()){
                int ind = mpp[rem] ;
                if(i - ind > 1)
                    return true ;
            }
            if(mpp.find(rem) == mpp.end())
                mpp[rem] = i ;
        }
        return false ;
    }
};
