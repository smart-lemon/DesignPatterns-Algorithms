
typedef struct listNode{
      int value;               /* value of the node */
      struct listNode* next;   /* points to the next linked-list node */
};


listNode* find_middle_node(listNode* head)
{
    listNode *fast = head, *slow = head;
    
    while(fast && fast->next) { 
        fast = fast->next->next;
        slow = slow->next; 
    }
    return slow;
}