#include "./../../../../Include/Common.h"

/*
    Given a singly linked list, group all odd nodes together followed by the even nodes.

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };



class Solution {
public:


    ListNode *createNode(int data){
        ListNode *node = new ListNode(data); 
        node->next = nullptr;
        return node;
    }
    

    ListNode* oddEvenList(ListNode* head) {
        ListNode *pEven = createNode(-1);
        ListNode *pOdd  = createNode(-1);
        ListNode *ahead, *curr;

        ahead = head->next; 
        curr = head; 
        
        while(ahead) {
            if(curr) {
                if(curr->val % 2 == 0){
                    pEven->next = curr; 
                    pEven = pEven->next;
                    pEven->next = nullptr;
                } else {
                    pOdd->next = curr; 
                    pOdd = pOdd->next;
                    pOdd->next = nullptr;
                }

                curr = ahead; 
                ahead = ahead->next;
            }
        }
    }
};