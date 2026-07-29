    vector<TreeNode*> solveMem(int start ,int end , map<pair<int , int> , vector<TreeNode*>> &mpp){
        if(start > end)
            return {NULL} ;

        if(start == end){
            TreeNode* root = new TreeNode(start) ; 
            return {root} ; 
        }   

        if(mpp.find({start , end}) != mpp.end())
            return mpp[{start ,end}] ;  

        vector<TreeNode*> res ; 
        for(int i = start ; i <= end ; i++){
            vector<TreeNode*> leftBst = solveMem(start , i-1 , mpp) ; 
            vector<TreeNode*> rightBst = solveMem(i+1 , end , mpp) ; 

            for(TreeNode* lr : leftBst){
                for(TreeNode* rr : rightBst){
                    TreeNode* root = new TreeNode(i) ; 
                    root -> left = lr ; 
                    root -> right = rr ; 
                    res.push_back(root) ; 
                }
            }
        }
        return mpp[{start ,end}] = res ; 
    }

    vector<TreeNode*> generateTrees(int n) {
        // return solve(1 , n) ; 
        map<pair<int , int> , vector<TreeNode*>> mpp ; 
        return solveMem(1 , n , mpp) ;
    }
