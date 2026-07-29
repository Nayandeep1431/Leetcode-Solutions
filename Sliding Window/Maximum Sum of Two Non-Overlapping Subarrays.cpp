class Solution {
public:
    int solve(vector<int> prefix , int m , int l ){
        int n = prefix.size() ; 
        int maxL =  0 ; 
        int res = 0 ; 

        for(int i =l+m-1 ; i < n ; i++){
            int lend = i - m ;
            int lstart = lend - l ;
            int mBlockSum = prefix[i] - prefix[lend] ; 
            int lBlockSum = prefix[lend] - ((lstart < 0) ? 0 : prefix[lstart]) ; 
            maxL = max(maxL , lBlockSum) ; 
            res = max(res , maxL + mBlockSum)  ;  
        }
        return res ;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size() ; 
        vector<int> prefix(n , 0)  ;
        prefix[0] = nums[0] ; 

        for(int i =1 ; i< n ; i++){
            prefix[i] = prefix[i-1] + nums[i] ; 
        }

        return max(solve(prefix , firstLen , secondLen) , solve(prefix , secondLen , firstLen)) ; 
    }
};
