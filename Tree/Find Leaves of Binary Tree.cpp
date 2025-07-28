
int solve(Node* root, map<int, vector<int>>& mpp) {
    if (root == NULL)
        return 0;

    int left = solve(root->left, mpp);
    int right = solve(root->right, mpp);

    int h = max(left, right) + 1;
    mpp[h].push_back(root->val);
    return h;
}

vector<vector<int>> findLeaves(Node* root) {
    vector<vector<int>> res;
    if (root == NULL)
        return res;

    map<int, vector<int>> mpp;
    solve(root, mpp);

    for (auto it : mpp) {
        res.push_back(it.second);
    }
    return res;
}
