#include "./../../../Include/Common.h"
using namespace std;

// namespace std have been included for this problem.
typedef struct listNode{
      int value;               /* value of the node */
      struct listNode* next;   /* points to the next linked-list node */
};

// Add any helper functions(if needed) above.
bool is_list_even(listNode* head)
{
    if(head == nullptr)
        return true;
    int ctr = 0; 
    
    listNode *runner = head;
    
    while(runner) {
        ctr++; 
        runner = runner->next; 
    }
    
    cout << ctr << endl;

    return ctr % 2 == 0;
}

// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
bool is_list_even_faster(listNode* head)
{
    if(head == nullptr)
        return true;

    listNode *runner = head;
    
    bool even = false; 
    while(runner) {
        if(runner->next){
            even = true; 
            runner = runner->next->next;
        } else {
            even = false; 
            break;
        }
    }
    return even;
}