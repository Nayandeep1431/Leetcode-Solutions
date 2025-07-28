class Solution {
  public:
    typedef long long ll ;
    bool isCompleteBT(Node* root) {
        // code here
        if(root == NULL)
            return true ;

        queue<pair<Node* , ll>> q ;
        ll pos = 0 ;
        q.push({root , pos}) ;
        while(!q.empty()){
            auto it = q.front() ;
            q.pop() ;
            Node* node = it.first ;
            ll val = it.second ;
            if(val != pos)
                return false ;

            pos++ ;
            if(node -> left)
                q.push({node -> left , 2* val +1}) ;
            if(node -> right)
                q.push({node -> right , 2* val + 2}) ;        
        }    
        return true ;
    }
};
