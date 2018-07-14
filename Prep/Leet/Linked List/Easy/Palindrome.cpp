#include "./../../../Include/Common.h"


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
    
    // Reverse the list O(n)
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
    
    // Check if the given list is a palindrome by comparing it to its reversed form
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