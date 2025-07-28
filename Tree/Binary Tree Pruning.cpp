class Solution {
public:
    bool check(TreeNode* root){
        if(!root)
            return false ;

        if(root -> val == 1)
            return true ;

        return (check(root -> right ) || check(root -> left)) ;        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL ;
        pruneTree(root -> left) ;
        pruneTree(root -> right) ;

        if(!check(root -> left))
            root -> left = NULL ;

        if(!check(root -> right))
            root -> right = NULL ;

        if(root -> left == NULL && root -> right == NULL && root -> val == 0)
            return NULL ;

        return root ;            
    }
};
