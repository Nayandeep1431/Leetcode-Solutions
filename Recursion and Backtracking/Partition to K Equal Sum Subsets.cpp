class Solution {
    bool solve(vector<int> &nums , vector<int> &vis , int k , int curr , int ind ,int target){
        if(k == 1)
            return true ;
        if(curr > target )
            return false ;
        if(ind >= nums.size())
            return false ;

        if(curr == target)
           return solve(nums , vis , k-1 , 0 , 0 , target) ;

        if(vis[ind] == 1)
            return solve(nums , vis ,k , curr , ind+1 , target) ;
        else{
            curr += nums[ind] ;
            vis[ind] = 1 ;
            bool op1 = solve(nums , vis , k ,curr ,ind+1 ,target) ;

            curr -= nums[ind] ;
            vis[ind] = false ;
            bool op2 = solve(nums , vis , k , curr , ind+1 , target) ;

            return op1 | op2 ;
        }                    
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> vis(n , 0) ;
        int sum = accumulate(nums.begin() , nums.end() ,0) ;
        if(sum % k != 0)
            return false ;

        int target = sum / k ;

        return solve(nums , vis , k , 0 ,0 , target) ;
    }
};
