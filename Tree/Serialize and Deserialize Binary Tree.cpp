/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "" ; 
        if (root == NULL)
            return ans ; 

        queue<TreeNode*> q ; 
        q.push(root) ; 
        while(!q.empty()){
            TreeNode* top = q.front() ; 
            q.pop() ; 

            if(top == NULL)
                ans += "#," ; 
           else{
                ans += to_string(top -> val) + "," ; 
                q.push(top -> left) ; 
                q.push(top -> right) ;
             }     
        }
        return ans ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0)
            return NULL ; 

        stringstream s(data) ; 
        string str ; 
        getline(s , str , ',') ; 
        queue<TreeNode*> q ; 
        TreeNode* root = new TreeNode(stoi(str)) ; 
        q.push(root) ; 

        while(!q.empty()){
            TreeNode* node = q.front() ; 
            q.pop() ; 

            getline(s , str , ',') ; 
            if(str != "#"){
                TreeNode* l = new TreeNode(stoi(str)) ; 
                node -> left = l ; 
                q.push(l) ;
            }

            getline(s , str , ',') ; 
            if(str != "#"){
                TreeNode* r = new TreeNode(stoi(str)) ; 
                node -> right = r ; 
                q.push(r) ;
            }
        }
        return root ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
