/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head){
        if(head == NULL)
            return 0 ; 
        ListNode* temp = head ; 
        int cnt = 0 ; 
        while(temp != NULL){
            cnt++ ; 
            temp = temp -> next ;
        }    
        return cnt ;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return NULL ; 

        int len = getLen(head) ; 
        ListNode* temp = head , *prev = NULL ; 
        int move = len / 2 ; 
        int cnt = 0 ; 
        while(temp != NULL && cnt < move){
            prev = temp ; 
            temp = temp -> next ; 
            cnt++ ;
        }    
        prev -> next = temp -> next ; 
        temp -> next = NULL ; 
        delete temp ;
        return head ;
    }
};
