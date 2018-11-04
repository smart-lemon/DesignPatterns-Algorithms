#include "./../../../../Include/Common.h"

/*
    344. Reverse string : 
    A function that returns the string reversed.

    https://leetcode.com/problems/reverse-string/
*/

class Solution {
public:
    // Approach : Two pointer
    string reverseString(string s) {
        int len = s.size();
        int front = 0, back = len - 1; 
        
        while(front < back){
            swap(s[front], s[back]);
            front++;
            back--;
        }
        return s; 
    }
};