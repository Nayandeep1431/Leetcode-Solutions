struct ListNode* oddEvenList(struct ListNode* head) {

    if(head == NULL || head -> next == NULL)
        return head ;
    struct ListNode* oh = malloc(sizeof(struct ListNode));
    oh->val = -1;
    struct ListNode* ot = oh;
    struct ListNode* eh = malloc(sizeof(struct ListNode));
    eh->val = -1;
    struct ListNode* et = eh;

    struct ListNode* curr = head;
    struct ListNode* temp;
    int cnt = 0 ;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        temp->next = NULL;

        if (cnt % 2 == 0) {
            ot->next = temp;
            ot = temp;
        } else {
            et->next = temp;
            et = temp;
        }
        cnt++ ;
    }
    ot->next = eh->next;
    return oh->next;
}
