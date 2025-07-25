class Solution {

public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
       map<int , int> mpp;
       mpp[0] = 1;
       int sum =0 ;
       int cnt =0;
       for(int i =0 ; i< n ; i++){
        sum += nums[i];
        int rem = sum -k ;
        cnt += mpp[rem];
        mpp[sum] += 1 ;
       }
       return cnt ;
    }
};
