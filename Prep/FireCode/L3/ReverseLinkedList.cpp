typedef struct listNode{
      int value;               /* value of the node */
      struct listNode *next;   /* points to the next linked-list node */
};

listNode* reverse_list(listNode* head)
{
    listNode *previous, *current, *ahead; 
    
    previous = nullptr; 
    current = head; 
    
    while(current) {
        ahead = current->next; 
        current->next = previous; 
        previous = current; 
        current = ahead; 
    }
    
    return previous;
}