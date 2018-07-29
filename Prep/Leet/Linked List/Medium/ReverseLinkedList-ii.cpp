#include "./../../../../Include/Common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // Should be on stack to avoid memory lea;
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        for (int i = 0; i < m - 1; i++)
            prev = prev->next;
        
        ListNode* runner = prev->next;
        for (int i = 0; i < n - m; i++) {
            ListNode* ahead = runner->next; 
            runner->next = ahead->next;
            ahead->next = prev->next;
            prev->next = ahead;
        }
        return dummy.next;
    }
};