class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        if (lists.empty())
            return nullptr;
            
        for (ListNode* list : lists) {
            if (list)
                pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            
            tail->next = top;
            tail = top;
            
            if (top->next)
                pq.push(top->next);
        }
        
        return dummy.next;
    }
};
