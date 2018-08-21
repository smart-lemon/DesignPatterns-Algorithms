
typedef struct listNode{
      int value;               /* value of the node */
      struct listNode *next;   /* points to the next linked-list node */
};

listNode* insert_at_position( listNode *head, int data, int pos)
{   
    listNode *newNode = new listNode;
    newNode->value = data; 
    
    
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return head; 
    }
    
    int cpos = 1;
    listNode *runner = head; 
    
    // Iterate to the previous position to pos
    while(cpos < pos - 1){
     
      // The input linked list was too short  
      if(runner == nullptr)
         return head;
            
        runner = runner->next; 
        cpos++; 
    }
    
    newNode->next = runner->next;
    runner->next = newNode; 
    
    return head;     
}