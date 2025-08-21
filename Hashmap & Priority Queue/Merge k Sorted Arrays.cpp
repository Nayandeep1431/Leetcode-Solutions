class Node{
    public: 
        int data ;
        int i  ;
        int j ;
        
        Node(int data , int i , int j){
            this -> data = data ;
            this -> i = i ;
            this -> j = j ;
        }
};

class compare {
public:
    bool operator()(const Node* a, const Node* b) const {
        return a->data > b->data;
    }
};   

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        // code here
        priority_queue<Node* , vector<Node*> , compare> pq ;
        
        for(int i =0 ; i< k ; i++){
            Node* temp = new Node(arr[i][0] , i , 0) ;
            pq.push(temp) ;
        }
        
        vector<int> ans ;
        while(!pq.empty()){
            Node* temp = pq.top() ;
            pq.pop() ;
            ans.push_back(temp -> data) ;
            
            int i = temp -> i ;
            int j = temp -> j ;
            
            if(j+1 < arr[i].size()){
                Node* v = new Node(arr[i][j+1] , i , j+1) ;
                pq.push(v) ;
            }
        }
        return ans ;
    }
};
