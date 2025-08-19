/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void nodeToParent(TreeNode* root , unordered_map<TreeNode* ,TreeNode*> &mpp){
        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty()){
            TreeNode* top = q.front() ;
            q.pop() ;

            if(top -> left){
                mpp[top -> left] = top;
                q.push(top -> left) ;
            }
            if(top -> right){
                mpp[top -> right] = top ;
                q.push(top -> right) ;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode* ,TreeNode*> mpp ;
         nodeToParent(root , mpp) ;

         unordered_map<TreeNode* ,bool> vis ;
         queue<TreeNode*> q ;
         int level = 0 ;

         q.push(target) ;
         vis[target] = true ;

         while(!q.empty()){
            int size = q.size() ;
            if(level++ == k)
                break ;

            for(int i =0 ; i< size ; i++){
                TreeNode* top = q.front() ;
                q.pop() ;
                if(top -> left && !vis[top -> left]){
                    vis[top -> left] = true ;
                    q.push(top -> left) ;
                }

                if(top -> right && !vis[top -> right]){
                    vis[top -> right] = true;
                    q.push(top -> right) ;
                }

                if(mpp[top] && !vis[mpp[top]]){
                    q.push(mpp[top]) ;
                    vis[mpp[top]] = true ;
                }
            }    
         }
         vector<int> res ;
         while(!q.empty()){
            res.push_back(q.front() -> val) ;
            q.pop() ;
         }
         return res ;
    }
};
