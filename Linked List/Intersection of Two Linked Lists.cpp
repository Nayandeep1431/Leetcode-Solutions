/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

    ListNode* move(ListNode* head , int n){
        int cnt = 0 ; 
        ListNode* temp = head ; 
        while(temp != NULL && cnt < n){
            cnt++ ;
            temp = temp -> next ;
        }
        return temp ;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL ; 

        int l1 = getLen(headA) ; 
        int l2 = getLen(headB) ; 

        if(l1 >= l2){
            headA = move(headA , l1-l2) ;
        }   
        else{
            headB = move(headB , l2-l1) ; 
        } 

        while(headA != NULL && headB != NULL){
            if(headA == headB)
                return headA ;
            headA = headA -> next ;
            headB = headB -> next ;    
        }
        return NULL;
    }
};
