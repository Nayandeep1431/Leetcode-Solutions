// Approach 1 
class Solution {
public:
   int maxi= 0 ;
    void solve(TreeNode* root , bool left , int steps){
        if(root == NULL)
            return ;

        maxi = max(maxi , steps) ;
        if(left){
            solve(root -> left , !left , steps+1) ;
            solve(root-> right , left , 1) ;
        }    
        else{
            solve(root -> right , !left , steps+1) ;
            solve(root-> left , left , 1) ;
        }
    }
    int longestZigZag(TreeNode* root) {
       solve(root , false , 0) ;
       solve(root , true , 0) ;
       return maxi ;
    }
};

// Approach 2 
class Solution {
public:
   int maxi= 0 ;
    void solve(TreeNode* root , int left , int right){
        if(root == NULL)
            return ;

      maxi = max({maxi , left , right}) ;
      solve(root -> left , right + 1, 0) ;
      solve(root -> right , 0 , left + 1) ;
    }
    int longestZigZag(TreeNode* root) {
      solve(root , 0 , 0) ;
       return maxi ;
    }
};
