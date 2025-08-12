class Solution {
    int solve(vector<int> &arr , int ind ,int target , vector<vector<int>> dp){
        if(ind ==0){
            if(target == 0 && arr[0] == 0)
                return 2 ;
            if(target == 0 || arr[0] == target)
                return 1 ;
            
                return 0 ;        
        }
        if(dp[ind][target] != -1)
            return dp[ind][target];

        int notPick = solve(arr ,ind-1 , target , dp);
        int pick = 0 ;
        if(arr[ind] <= target)
            pick = solve(arr , ind-1 , target - arr[ind] , dp);

        dp[ind][target] = pick + notPick ;
        return dp[ind][target] ;         
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum =0 ;
        for(int i =0 ; i< nums.size() ; i++){
            totalSum += nums[i];
        }
        if(totalSum < target)
            return 0 ;

        if((totalSum - target) % 2 == 1)
            return 0 ;

        int s2 = (totalSum - target) / 2 ;
        int n = nums.size() ;
 
        vector<vector<int>> dp(n , vector<int> (s2+1 , 0));
        // int ans = solve(nums ,n-1 , s2 , dp);  
        // return ans ;  

        if(nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] =1 ;
        if(nums[0] != 0 && nums[0] <= s2)
            dp[0][nums[0]] = 1;

        for(int ind = 1 ; ind< n ; ind++){
            for(int tar = 0 ; tar<= s2 ; tar++){
                int np = dp[ind-1][tar];
                int pick =0 ;
                if(nums[ind] <= tar)
                    pick = dp[ind-1][tar- nums[ind]];

                dp[ind][tar] = pick + np ;     
            }
        }   
        return dp[n-1][s2] ;             
    }
};
