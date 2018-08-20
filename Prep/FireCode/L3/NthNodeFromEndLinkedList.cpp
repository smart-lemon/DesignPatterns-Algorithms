#include "./../../../Include/Common.h"

typedef struct listNode{
      int value;               /* value of the node */
      struct listNode* next;   /* points to the next linked-list node */
};


listNode* find_n_node_from_end(listNode* head, int n)
{
     if(head == nullptr){
        return head; 
    }
    
    listNode *dummy = new listNode;
    dummy->next = head;

    listNode *fast = dummy; 
    
    for(int i = 0; i < n;  i++ )
    {   
        fast = fast->next;
        
        // if the input n is purposely wrong  
        if(fast == nullptr && i < n)
            return nullptr;
    }

    listNode *slow = dummy;
    
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow->next;

}