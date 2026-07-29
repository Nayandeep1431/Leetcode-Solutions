class Solution {
public:
    typedef vector<TreeNode*> v ; 
    v solve(int n){
        if(n % 2 == 0){
            return {} ;
        }

        if(n == 1){
            TreeNode* root = new TreeNode(0) ; 
            return {root} ; 
        }

        v res ; 
        for(int i = 1 ; i< n ; i+=2){
            v leftBT = solve(i) ; 
            v rightBT = solve(n-i-1) ; 

            for(TreeNode* l : leftBT){
                for(TreeNode* r : rightBT){
                    TreeNode* root = new TreeNode(0) ; 
                    root -> left = l ; 
                    root -> right = r ; 

                    res.push_back(root) ; 
                }
            }
        }
        return res ;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n) ;
    }
};
