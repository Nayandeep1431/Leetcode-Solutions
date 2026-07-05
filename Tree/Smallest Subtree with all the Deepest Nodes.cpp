class Solution {
    pair<TreeNode* , int> mpp(TreeNode* root){
        if(root == NULL)
            return {NULL , 0} ;

        auto left = mpp(root -> left) ;
        auto right = mpp(root -> right) ;

        if(left.second > right.second)
            return {left.first , left.second +1} ;

        if(right.second > left.second)
            return {right.first , right.second +1} ;

        return {root , left.second +1} ;            
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return mpp(root).first ;
    }
};
