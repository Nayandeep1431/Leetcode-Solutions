class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL)
            return "" ;

        string ans = to_string(root -> val) ;
        string l = tree2str(root -> left) ;
        string r = tree2str(root -> right) ;

        if(!root -> left && !root -> right)
            return ans ;
        if(!root -> right)
           return ans + "("+ l +")" ;
        if(!root -> left)
            return ans + "(" + ")" + "("+r+")" ;

        return ans + "("+ l+ ")" + "("+ r+")" ;               
    }
};
