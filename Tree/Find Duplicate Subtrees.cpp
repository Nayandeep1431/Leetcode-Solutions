class Solution {
public:
    string serialize(TreeNode* root, unordered_map<string, int>& subtreeCount, vector<TreeNode*>& result) {
        if (!root) return "#";

        string left = serialize(root->left, subtreeCount, result);
        string right = serialize(root->right, subtreeCount, result);
        string subtree = to_string(root->val) + "," + left + "," + right;

        if (subtreeCount[subtree] == 1) {
            result.push_back(root);
        }
        subtreeCount[subtree]++;
        return subtree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeCount;
        vector<TreeNode*> result;
        serialize(root, subtreeCount, result);
        return result;
    }
};
