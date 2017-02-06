struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* now = head;
    while (now->next != NULL){
        if (now->val == now->next->val)
            now->next = now->next->next;
        else
            now = now->next;
    }
    return head;
}

