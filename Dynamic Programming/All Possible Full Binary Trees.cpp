class Solution {
public:
    typedef vector<TreeNode*> v ; 
    map<int , v> mpp ; 
    v solve(int n){
        if(n % 2 == 0){
            return {} ;
        }

        if(n == 1){
            TreeNode* root = new TreeNode(0) ; 
            return {root} ; 
        }

        if(mpp.find(n) != mpp.end())
            return mpp[n] ; 

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
        return mpp[n] = res ;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n) ;
    }
};
