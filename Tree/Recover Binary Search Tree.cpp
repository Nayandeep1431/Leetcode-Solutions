class Solution {
  public:
    void inorder(Node* root , Node* &prev , Node* &last , Node* &first , Node* &mid){
        if(root == NULL)
            return ; 
        
        inorder(root -> left , prev , last , first , mid) ; 
        if(prev && root -> data < prev -> data){
            if(!first){
                first = prev ; 
                mid = root ; 
            }
            else
                last = root ; 
        }
        prev = root ; 
        inorder(root -> right , prev , last , first , mid) ; 
    }
    void correctBST(Node* root) {
        // add code here.
        Node* prev = NULL , *first = NULL , *last = NULL  , *middle = NULL ; 
        inorder(root, prev , last , first , middle) ; 
        if(first && last)
            swap(first -> data , last -> data) ; 
        else
            swap(first -> data , middle -> data) ; 
    }
};
