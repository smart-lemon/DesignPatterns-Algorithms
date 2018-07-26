/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *runner1 = l1, *runner2 = l2; 
        ListNode *outputHead = nullptr, *outputPrev = new ListNode(0), *outputRunner = nullptr;
        
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        while(runner1 && runner2) {
            if(runner1->val < runner2->val) {
                cout << "R1 < R2 " << runner1->val << " " << runner2->val << " ";
                outputRunner = new ListNode(runner1->val);
                outputPrev->next = outputRunner;
                runner1 = runner1->next;
            } else if(runner1->val > runner2->val) {
                cout << "R1 > R2 " << runner1->val << " " << runner2->val << " ";
                outputRunner = new ListNode(runner2->val);
                outputPrev->next = outputRunner;
                runner2 = runner2->next;
            } else if(runner1->val == runner2->val) {
                cout << "Equal " << runner1->val << " " << runner2->val << " ";
                outputRunner = new ListNode(runner1->val);
                outputPrev->next = outputRunner;
                outputPrev = outputPrev->next;
                runner1 = runner1->next;
                outputRunner = new ListNode(runner2->val);
                outputPrev->next = outputRunner;
                runner2 = runner2->next;
            }
            
            if(outputHead == nullptr) {
                outputHead = outputPrev;
            }
            outputPrev = outputPrev->next;
        }
        
        if(runner1) {
           if(outputHead == nullptr) {
                return runner1;
            }
           cout << "Append " << runner1->val << " ";
           outputPrev->next = runner1;
        }
        if(runner2) {
           if(outputHead == nullptr) {
                return runner2;
           }
           cout << "Append " << runner2->val << " ";

           outputPrev->next = runner2;
        }
        
       return outputHead->next;
    }
};