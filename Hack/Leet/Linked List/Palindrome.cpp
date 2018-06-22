#include "./../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>


// https://leetcode.com/problems/palindrome-linked-list/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *createNode(int data){
        ListNode *node = new ListNode(data); 
        node->next = nullptr;
        return node;
    }
    
    ListNode *reverseList(ListNode *head) {
        ListNode *tail = nullptr, *temp = nullptr, *runner = head;

        if(head == nullptr)
            return nullptr;
        
        tail = createNode(head->val);
        
        while(runner->next) {
            runner = runner->next;
            temp = createNode(runner->val); 
            temp->next = tail;
            tail = temp;
        }
        return tail;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        
        ListNode *node = reverseList(head);
        ListNode *runner = head; 
        
        bool isPalindrome = false; 
         while(runner && node) {
             if(runner->val == node->val){
                   runner = runner->next;
                   node = node->next;
                   isPalindrome = true;
             } else {
                 isPalindrome = false;
                 break;
             }     
        }  
        return isPalindrome;
    }
};