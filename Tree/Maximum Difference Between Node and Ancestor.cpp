class Solution {
public:
    void solve(TreeNode* root ,int maxVal , int minVal , int &maxi){
        if(root == NULL)
            return  ;

        int val = root -> val ;
        maxVal = max(val , maxVal) ;
        minVal = min(minVal , val) ;

        maxi = max(maxi , abs(maxVal - minVal)) ;
        solve(root -> left , maxVal , minVal , maxi) ;
        solve(root -> right , maxVal , minVal , maxi) ;
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi1 = INT_MIN ;
        int maxi2 = INT_MIN ;

        solve(root ->left , root -> val, root -> val , maxi1) ;
        solve(root -> right , root -> val, root -> val , maxi2) ;

        return max(maxi1, maxi2) ;
    }
};
