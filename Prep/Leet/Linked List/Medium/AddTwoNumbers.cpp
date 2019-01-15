#include "./../../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>


// https://leetcode.com/problems/add-two-numbers/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 
class Solution {
public:
    ListNode *createNode(int num) {
        return new ListNode(num); 
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode preHead(0), *p = &preHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            p->next = createNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};