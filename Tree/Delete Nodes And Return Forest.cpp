class Solution {
public:
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& res) {
        if (!root) return nullptr;

        root->left = deleteHelper(root->left, st, res);
        root->right = deleteHelper(root->right, st, res);

        if (st.count(root->val)) {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;

        TreeNode* updatedRoot = deleteHelper(root, st, res);
        if (updatedRoot) res.push_back(updatedRoot);

        return res;
    }
};
