class Solution {
  public:
    void solve(Node* root , int cnt , int &maxi , int prev){
        if(root == NULL)
            return  ; 
        
        if(root -> data == prev+ 1)
            cnt = cnt + 1 ;
        else
            cnt = 1 ;
        
        maxi = max(maxi , cnt) ;
        
        solve(root ->left, cnt , maxi , root -> data) ; 
        solve(root ->right, cnt , maxi , root -> data) ; 
    }
    int longestConsecutive(Node* root) {
        // code here
        int maxi1 = -1 ,maxi2 = -1 ; 
        solve(root -> left , 1 , maxi1 , root ->data) ; 
        solve(root ->right , 1 , maxi2 , root -> data) ;
        
        int maxi = max(maxi1 , maxi2) ; 
        return (maxi == 1) ?-1 : maxi  ; 
    }
};
