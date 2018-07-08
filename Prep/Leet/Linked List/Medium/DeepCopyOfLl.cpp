/**
 * Definition for singly-linked list with a random pointer.
 */ 


// https://leetcode.com/problems/copy-list-with-random-pointer/

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

 
 
 class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead, *first, *second;
        if (head == nullptr) return nullptr;

        // Splice
        for (first = head;  first != nullptr; first = first->next->next) {
            second = new RandomListNode(first->label);
            second->next = first->next;
            first->next = second;
        }

        // Make a new head 
        newHead = head->next;
        for (first = head;  first != nullptr; first = first->next->next) {
            if(first->random) {
                second = first->next;
                second->random = first->random->next;
            }
        }
        
        // Run
        for (first = head; first != nullptr; first = first->next) {
            second = first->next;
            first->next = second->next;
            if (second->next != nullptr) 
                second->next = second->next->next;
        }
        return newHead;
    }
};