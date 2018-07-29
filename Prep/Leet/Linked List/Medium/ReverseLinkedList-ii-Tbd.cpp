#include "./../../../../Include/Common.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };


ListNode *reverse(ListNode* head, int count, int n){
    ListNode *runner = head, *ahead, *rprev, *start,  *output; 
    
              
    rprev = head;
    start = rprev; 
    runner = runner->next;
    cout << endl << " Start reversing  " << endl;

    while(runner && count < n) {  
        cout << " " <<  runner->val << "<-";  
        ahead = runner->next; 
        runner->next = rprev; 
        rprev = runner;
        runner = ahead;
        count++;
    }
    start->next = ahead; 
    output = runner; 
    
    cout << " Reverse " << endl;

    runner = head; 
    while(runner) {
        cout << " " <<  runner->val << "->";
        runner = runner->next;
    }
    
    cout << " Fin Rev ";
    return output;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode *runner = head;
        ListNode *prev; 
        
        if(n < m)
            return nullptr; 
        
        while(runner && count < m) {
             cout << "Pre " <<  runner->val << "->";
             prev = runner;
             runner = runner->next;
             count++;
        }
        
        prev->next = reverse(runner, count, n);
        
        cout << " Appended " << endl;
        runner = head; 
        while(runner) {
            cout << " " <<  runner->val << "->";
            runner = runner->next;
        }
        return head;
    }
};