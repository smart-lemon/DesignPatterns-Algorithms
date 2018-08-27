
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

/*
    206.
    https://leetcode.com/problems/reverse-linked-list/description/
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // [previous] -> [current] -> [ahead]
        ListNode *previous, *current, *ahead; 
        previous = nullptr; 
        current = head; 

        while(current) {
            ahead = current->next;    // [current]  -> [ahead]
            current->next = previous; // [previous] <- [current]
            previous = current;     
            current = ahead; 
        }

        return previous;
    }

    ListNode* reverseListRecursive(ListNode *head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};