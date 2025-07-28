class Solution {
public:
    void leaf(TreeNode* root , vector<int> &arr){
        if(root == NULL)
            return ;

        if(root -> left == NULL && root -> right == NULL){
            arr.push_back(root -> val) ;
            return ;
        }  
        leaf(root -> left , arr) ; 
        leaf(root -> right , arr) ;     
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1 ;
         leaf(root1 , tree1) ;
        vector<int> tree2 ;
         leaf(root2 , tree2) ;

        if(tree1.size() != tree2.size())
            return false ;

        for(int i =0 ; i< tree1.size() ; i++){
            if(tree1[i] != tree2[i])
                return false ;
        }    
        return true ;
    }
};
