
/*
    876.
    https://leetcode.com/problems/middle-of-the-linked-list/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
    
        while(fast && fast->next && fast->next->next) { 
            fast = fast->next->next;
            slow = slow->next; 
        }
        return slow;
    }
};