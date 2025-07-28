class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        return left + right + root->val;
    }

    int ans(TreeNode* root, int total, ll &maxi) {
        if (root == NULL)
            return 0;

        int left = ans(root->left, total, maxi);
        int right = ans(root->right, total, maxi);

        maxi = max(maxi, (ll)(total - left) * left);
        maxi = max(maxi, (ll)(total - right) * right);

        return left + right + root->val;
    }

    int maxProduct(TreeNode* root) {
        int total = solve(root);
        ll maxi = 0;
        ans(root, total, maxi);
        return maxi % mod; 
    }
};
