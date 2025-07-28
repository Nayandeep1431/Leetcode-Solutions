class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int d = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (d == depth - 1) {
                    TreeNode* newNode = new TreeNode(val);
                    newNode->left = top->left;
                    top->left = newNode;

                    newNode = new TreeNode(val);
                    newNode->right = top->right;
                    top->right = newNode;
                } else {
                    if (top->left) q.push(top->left);
                    if (top->right) q.push(top->right);
                }
            }
            d++;
        }
        return root;
    }
};
