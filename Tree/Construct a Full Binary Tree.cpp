class Solution {
public:
    typedef vector<int> v;
    int n;

    void mapping(v &preM, unordered_map<int, int> &mpp) {
        for (int i = 0; i < preM.size(); i++) {
            mpp[preM[i]] = i;
        }
    }

    Node* solve(int &ind, int start, int end,
                v &pre, v &preM,
                unordered_map<int, int> &mpp) {

        if (ind >= n || start > end)
            return NULL;

        Node* root = new Node(pre[ind++]);

        if (start == end || ind >= n)
            return root;

        int pos = mpp[pre[ind]];

        // left subtree
        if (pos <= end)
            root->left = solve(ind, pos, end, pre, preM, mpp);

        // right subtree
        if (ind < n)
            root->right = solve(ind, start + 1, pos - 1, pre, preM, mpp);

        return root;
    }

    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {

        n = pre.size();

        unordered_map<int, int> mpp;
        mapping(preMirror, mpp);

        int ind = 0;

        return solve(ind, 0, n - 1, pre, preMirror, mpp);
    }
};
