/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* isCycle(Node* head){
        if(head == NULL || head -> next == NULL)
            return NULL ;
        
        Node* slow = head ;
        Node* fast = head ;
        
        while(fast != NULL && slow != NULL){
            fast = fast -> next ;
            if(fast != NULL)
                fast = fast -> next ;
            
            slow = slow -> next ;
            
            if(fast == slow)
                return slow ;
        }
        return NULL ;
    }
    
    Node* start(Node* head){
                if(head == NULL)
            return NULL ;
        
        Node* inter =   isCycle(head) ;
        if(inter == NULL)
            return NULL ;
        
        Node* slow = inter ;
        Node* fast = head ;
        while(slow != fast){
            slow = slow -> next ;
            fast = fast -> next ;
        }
        return slow ;
    }
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL)
            return 0 ;
        
        Node* s = start(head) ;
        Node* temp =s ;
        if(s == NULL)
            return 0 ;
        int cnt = 1 ;
        while(s -> next != temp){
            s = s-> next ;
            cnt++ ;
        }
        return cnt ;
    }
};
