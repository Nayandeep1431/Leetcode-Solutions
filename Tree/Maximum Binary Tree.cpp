class Solution {
public:
    typedef pair<int, int> p ;
    priority_queue<p> pq ;
    TreeNode* solve(int start , int end , vector<int> &nums){
        if(start > end)
            return NULL ;
        if(start >= nums.size())
            return NULL ; 
        int maxi = INT_MIN , maxInd = -1 ;   
        for(int i =start ; i<= end ; i++){
            int ele = nums[i] ;
            if(maxi < ele){
                maxi = ele ;
                maxInd = i ;
            }
        }
        TreeNode* root =new TreeNode(maxi) ;
        root -> left = solve(start , maxInd-1 , nums) ;
        root -> right = solve(maxInd +1 , end , nums) ;
        return root ;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size() ;
        return solve(0 , n-1 , nums) ;
    }
};
