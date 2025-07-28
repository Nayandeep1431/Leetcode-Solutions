class Solution {
public:
    unordered_map<int , int> mpp ;
    void solve(int ind , vector<int> &nums , int val ){
        if(ind == nums.size()){
            mpp[val]++ ;
            return ;
        }
        solve(ind+1, nums , val | nums[ind]) ;
        solve(ind+1 , nums , val) ;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        solve(0 , nums , 0) ;
        int maxi = 0 , maxiCnt  =0 ;
        for(auto it : mpp){
            if(it.first > maxi){
                maxi = it.first ;
                maxiCnt = it.second ;
            }
        }
        return maxiCnt ;
    }
};
