class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        Node* temp = head ; 
        while(temp != NULL){
            Node* curr = temp -> next ;
            if(temp -> data == x){
                if(temp == head){
                    head = head -> next ; 
                    head -> prev = NULL ; 
                    temp -> next = NULL ; 
                    delete temp ;
                }
                else if(temp -> next == NULL){
                    temp -> prev -> next = temp -> next ; 
                    temp -> prev = NULL ; 
                    delete temp ; 
                }
                else{
                    temp -> prev -> next = temp -> next ; 
                    temp -> next -> prev = temp -> prev ; 
                    temp -> next = NULL ; 
                    temp -> prev = NULL ; 
                    delete temp ;
                }
            }
            temp = curr ;
        }
        return head ;
    }
};
