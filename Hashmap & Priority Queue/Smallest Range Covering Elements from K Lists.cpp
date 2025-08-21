class Node {
public:
    int data;
    int i;
    int j;
    
    Node(int data, int i, int j) {
        this->data = data;
        this->i = i;
        this->j = j;
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push(new Node(nums[i][0], i, 0));
        }
        
        int start = mini;
        int end = maxi;
        
        while(!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            
            mini = temp->data;
            if(maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            
            int i = temp->i;
            int j = temp->j;
            delete temp;
            
            if(j + 1 < nums[i].size()) {
                maxi = max(maxi, nums[i][j + 1]);
                pq.push(new Node(nums[i][j + 1], i, j + 1));
            } else {
                break;
            }
        }
        
        return {start, end};
    }
};
