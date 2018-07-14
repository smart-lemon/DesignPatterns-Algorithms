/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode* head, int count, ListNode *prev){
    ListNode *runner = head, *ahead, *current; 
        while(runner) {
                
            if(runner){
                prev = runner; 
                current = runner; 
                runner = runner->next; 
                current->next = prev;
            }
        }
        return runner;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 0;
        ListNode *runner = head;
        ListNode *prev; 
        
        if(n < m)
            return nullptr; 
        
        while(runner && count < m) {
             prev = runner;
             runner = runner->next;
             count++;
        }
        reverse(runner, n-m, prev);
    }
};