class Solution {
    int solve(TreeNode* root, int &maxi) {
        if (root == nullptr) {
            return 0;
        }

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);

        left = (left < 0) ? 0 : left ;
        right = (right < 0) ? 0 : right ;
        
        int val = max(max(left, right) + root->val, root->val);
        maxi = max(maxi, left + right + root->val); 
        return val;    
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int maxi = INT_MIN;
        solve(root, maxi); 
        return maxi;   
    }
};
