
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

/*
    206.
    https://leetcode.com/problems/reverse-linked-list/description/
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *previous, *current, *ahead; 

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
};