#include "./../../../../Include/Common.h"

/*
    28. Implement strStr() - Return the index of the first occurrence of needle in haystack, 
        or -1 if needle is not part of haystack.
        https://leetcode.com/problems/implement-strstr/
*/

/*
    For the purpose of this problem, we will return 0 when needle is an
    empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.length(), needle_len = needle.length(), i, j;
        if (needle_len == 0) {
            return 0;
        }
        for (i = 0; i < haystack_len - needle_len + 1; i++) {
            for (j = 0; j < needle_len; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needle_len) {
                return i;
            }
        }
        return -1;
    }


    /*
        KMP  
    */

   public:
    int strStrUsingKmp(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m; ) {
            if (haystack[i] == needle[j]) { 
                i++;
                j++;
            }
            if (j == n) {
                return i - j;
            }
            if ((i < m) && (haystack[i] != needle[j])) {
                if (j) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return -1;
    }
    private:
        vector<int> kmpProcess(string& needle) {
            int n = needle.length();
            vector<int> lps(n, 0);
            for (int i = 1, len = 0; i < n; ) {
                if (needle[i] == needle[len]) {
                    lps[i++] = ++len;
                } else if (len) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
            return lps;
        }
};