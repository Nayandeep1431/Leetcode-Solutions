class Solution {
public:
    vector<TreeNode*> solve(int start ,int end){
        if(start > end)
            return {NULL} ;

        if(start == end){
            TreeNode* root = new TreeNode(start) ; 
            return {root} ; 
        }    
        vector<TreeNode*> res ; 
        for(int i = start ; i <= end ; i++){
            vector<TreeNode*> leftBst = solve(start , i-1) ; 
            vector<TreeNode*> rightBst = solve(i+1 , end) ; 

            for(TreeNode* lr : leftBst){
                for(TreeNode* rr : rightBst){
                    TreeNode* root = new TreeNode(i) ; 
                    root -> left = lr ; 
                    root -> right = rr ; 
                    res.push_back(root) ; 
                }
            }
        }
        return res ; 
    }
    vector<TreeNode*> generateTrees(int n) {
         return solve(1 , n) ; 

    }
};
