class Solution {
public:
    int solve(TreeNode* root ,int maxi ){
        if(root == NULL)
            return 0;

        int cnt = 0 ; 
        if(root -> val >= maxi)
            cnt = 1 ;

        maxi = max(root -> val , maxi) ; 
        cnt += solve(root -> left , maxi) ;
        cnt += solve(root -> right , maxi) ; 
        return cnt ;      
 
    }
    int goodNodes(TreeNode* root) {
        return solve(root ,root -> val) ; 
    }
};
