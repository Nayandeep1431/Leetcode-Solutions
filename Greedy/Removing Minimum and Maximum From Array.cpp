class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size() ;
        int mini = INT_MAX ;
        int minInd = -1 ;
        int maxi = INT_MIN ;
        int maxInd = -1 ;
        for(int i = 0 ; i< n ; i++){
            int ele = nums[i] ;
            if(nums[i] > maxi){
                maxi = ele ;
                maxInd = i ;
            }

            if(nums[i] < mini){
                mini = ele ;
                minInd = i ;
            }
        }
        int aagese = max(minInd , maxInd) +1 ;
        int pichese = n - min(minInd , maxInd) ; 
        int bothside = min(minInd , maxInd) + 1 + n - max(minInd ,maxInd) ;
        return min({aagese ,pichese , bothside}) ;
    }
};
