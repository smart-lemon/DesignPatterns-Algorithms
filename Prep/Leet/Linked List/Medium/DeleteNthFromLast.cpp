#include "./../../../../Include/Common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       if(head == nullptr){
           return head; 
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *fast = dummy; 
        
        for(int i = 0; i < n;  i++ )
        {   
            fast = fast->next;
        }

        ListNode *slow = dummy;
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return dummy->next;
    }
};