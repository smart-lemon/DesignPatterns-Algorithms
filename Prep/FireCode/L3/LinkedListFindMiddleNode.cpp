
typedef struct listNode{
      int value;               /* value of the node */
      struct listNode* next;   /* points to the next linked-list node */
};


listNode* find_middle_node(listNode* head)
{
    listNode *fast = head, *slow = head;
    
    // This is different for Leetcode, it expects the floor node of the middle in case of even 
    while(fast && fast->next && fast->next->next) { 
        fast = fast->next->next;
        slow = slow->next; 
    }
    return slow;
}