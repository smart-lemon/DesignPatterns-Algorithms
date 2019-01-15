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
    ListNode *createNode() {
        return new ListNode(0); 
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1head = l1, *l2head = l2; 
        ListNode *l1runner = l1, *l2runner = l2;
        ListNode *outputHead, *output, *prevOutput; 
        int carry = 0; 
        output = createNode();
        outputHead = output;
                
        while(l1runner != NULL && l2runner != NULL) {
            output->val = l1runner->val + l2runner->val + carry; 
            carry =  output->val / 10; 
            output->val = output->val % 10;                        
            output->next = createNode();
            prevOutput = output;
            l1runner = l1runner->next;
            l2runner = l2runner->next;
            output = output->next;
        }
        
        while(l1runner != NULL) {
            output->val = l1runner->val + carry; 
            carry =  output->val / 10; 
            output->val = output->val % 10; 
            output->next = createNode();
            l1runner = l1runner->next;
            prevOutput = output;
            output = output->next;
        }
        
        while(l2runner != NULL) {
            output->val = l2runner->val + carry; 
            carry =  output->val / 10; 
            output->val = output->val % 10; 
            output->next = createNode();
            l2runner = l2runner->next; 
            prevOutput = output;
            output = output->next;
        }
        
        if(carry){
            output->val = carry;
            output->next == NULL;
        } else {
            prevOutput->next = NULL;
        }
        return outputHead;
    }
};