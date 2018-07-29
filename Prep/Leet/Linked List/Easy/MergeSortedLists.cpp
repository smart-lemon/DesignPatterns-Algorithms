/*
    21. https://leetcode.com/problems/merge-two-sorted-lists/description/ 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *runner1 = l1, *runner2 = l2; 
        ListNode *dummy = nullptr, *outputRunner = nullptr;
        ListNode *outputPrev = new ListNode(0); // dummy
        
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        // The head is initially a dummy 
        dummy = outputPrev;
        
        while(runner1 && runner2) {
            if(runner1->val < runner2->val) {
                outputRunner = new ListNode(runner1->val);
                outputPrev->next = outputRunner;
                runner1 = runner1->next;
            } else if(runner1->val > runner2->val) {
                outputRunner = new ListNode(runner2->val);
                outputPrev->next = outputRunner;
                runner2 = runner2->next;
            } else if(runner1->val == runner2->val) {
                outputRunner = new ListNode(runner1->val);
                outputPrev->next = outputRunner;
                outputPrev = outputPrev->next;
                runner1 = runner1->next;
                outputRunner = new ListNode(runner2->val);
                outputPrev->next = outputRunner;
                runner2 = runner2->next;
            }            
            outputPrev = outputPrev->next;
        }       
        
        if(runner1) {
            if(dummy->next == nullptr)
                return runner1;
           outputPrev->next = runner1;
        }
        if(runner2) {
           if(dummy->next == nullptr)
                return runner2;
           outputPrev->next = runner2;
        }
        
       return dummy->next;
    }
};