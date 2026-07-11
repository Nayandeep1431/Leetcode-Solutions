class Solution {
public:

    pair<int,int> solve(TreeNode* root, int &maxi){

        if(root == NULL)
            return {-1, 0};

        auto left = solve(root->left, maxi);
        auto right = solve(root->right, maxi);

        int leftLen = 0;
        int rightLen = 0;

        if(root->left && root->left->val == root->val)
            leftLen = left.second + 1;

        if(root->right && root->right->val == root->val)
            rightLen = right.second + 1;


        maxi = max(maxi, leftLen + rightLen);

        return {root->val, max(leftLen, rightLen)};
    }

    int longestUnivaluePath(TreeNode* root) {

        int maxi = 0;
        solve(root, maxi);
        return maxi;
    }
};
