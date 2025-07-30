class Solution {
public:
    typedef pair<int , int> p ;
    pair<int , int> solve(TreeNode* root , int &cnt){
        if(root == NULL){
            return {0 , 0} ;
        }

        p l = solve(root -> left , cnt) ;
        p r = solve(root -> right , cnt) ;

        int val = root -> val + l.first + r.first ;
        int total = 1 + l.second + r.second ;

        if((val / total) == root -> val)
            cnt++ ;

        return {val ,total} ;    
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0 ;
        solve(root , cnt) ;
        return cnt ;
    }
};
