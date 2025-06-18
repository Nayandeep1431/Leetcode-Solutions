class Solution {
    unordered_map<int , list<int>> mpp ;
    int search(int ele , int prev){
        int ind = -1 ;
        for(auto it : mpp[ele]){
            if(it > prev){
                ind = it ;
                break ;
            }
        }
        return ind ;
    }
    int solve(vector<int>& nums1, vector<int>& nums2 , int ind ,int prev){
        if(ind >= nums1.size())
            return 0 ;

        int exclude = solve(nums1, nums2 , ind+1 ,prev) ;
        int take =0 ;
        int val = search(nums1[ind] , prev ) ;
        if(val != -1 && val > prev){
            prev = val ;
            take = 1 + solve(nums1 , nums2 , ind+1 , prev) ;
        }    
        return max(exclude , take ) ; 
    }

    int solveMem(vector<int>& nums1, vector<int>& nums2 , int ind , int prev, vector<vector<int>> &dp){
        if(ind >= nums1.size())
            return 0 ;

        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];

        int exclude = solveMem(nums1, nums2, ind+1, prev, dp);
        int take = 0;

        int val = search(nums1[ind], prev);
        if(val != -1) {
            take = 1 + solveMem(nums1, nums2, ind+1, val, dp);
        }
        return dp[ind][prev+1] = max(exclude, take);
    }

    int solveTab(vector<int> &nums1 , vector<int> &nums2){
        int n = nums1.size() ;
        int m = nums2.size() ;

        vector<vector<int>> dp(n+1 , vector<int> (m+2 , 0)) ;
        for(int i = n-1 ; i>=0 ; i-- ){
            for(int prev = m-1 ; prev>= -1 ; prev--){
                int exclude = dp[i+1][prev+1] ;
                int take = 0 ;
                int val = search(nums1[i] , prev) ;
                if(val != -1)
                    take = 1 + dp[i+1][val+1] ;

                dp[i][prev+1] = max(exclude , take) ;     
            }
        }
        return dp[0][0] ;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int prev = -1 ;
        // return solve(nums1 , nums2 , 0 , prev) ;
        
        int n = nums1.size() ;
        int m = nums2.size() ;

        for(int i = 0 ; i< m ; i++){
            mpp[nums2[i]].push_back(i) ;
        }
        vector<vector<int>> dp(n , vector<int> (m+2 , -1)) ;
        // return solveMem(nums1 , nums2 , 0 , prev , dp) ;

        return solveTab(nums1 , nums2) ;
    }
};
