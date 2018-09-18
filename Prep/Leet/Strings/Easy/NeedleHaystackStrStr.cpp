#include "./../../../../Include/Common.h"

/*
    28. Implement strStr() - Return the index of the first occurrence of needle in haystack, 
        or -1 if needle is not part of haystack.
        https://leetcode.com/problems/implement-strstr/
*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0; 
        
        /*
            For the purpose of this problem, we will return 0 when needle is an
            empty string. This is consistent to C's strstr() and Java's indexOf().


        */
        if(needle.length() == 0)
            return 0;

        for(i = 0; i < haystack.length(); i++){
            j = 0;
            if(haystack[i] == needle[j]){
                int index = i;
               for(j = 0; j < needle.length(); j++, i++){
                    if(haystack[i] != needle[j]){
                        i = index;
                        break;
                    } else {
                        if(j ==  needle.length() - 1){
                            return index;
                        }    
                    }
               }
            }
        }
        return -1;
    }
};