/*
    237. 
     https://leetcode.com/problems/delete-node-in-a-linked-list/
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    // slower
    void deleteNodeSlow(ListNode* node) {
        ListNode *prev = nullptr;
        while(node->next){
            prev = node; 
            node->val = node->next->val;
            node = node->next; 
        }
        prev->next = nullptr; 
    }

    // correct answer
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};