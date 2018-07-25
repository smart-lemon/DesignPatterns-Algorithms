
typedef struct listNode{
      int value;               /* value of the node */
      struct listNode* next;   /* points to the next linked-list node */
};
// Add any helper functions(if needed) above.
listNode* delete_at_pos(listNode* head, int n)
{   
    
    if (n <= 0 || head == nullptr)
        return head;
    if(n == 1)
        return head->next;
    
    listNode *node = head, *prev = nullptr;
    int k = 1;
    
    while(node != nullptr) {
        if(k == n)
            break;
        prev = node; 
        node = node->next; 
        k++; 
    }
    if(node)
         prev->next = node->next; 
    else 
        prev->next = nullptr;

    return head;
}