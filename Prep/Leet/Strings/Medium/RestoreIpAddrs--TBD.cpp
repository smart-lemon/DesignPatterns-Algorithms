#include "./../../../../Include/Common.h"

/*
    Given a string of digits, generate all possible valid IP address combinations.
    IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers between 0 and 255. 
    Zero-prefixed numbers, such as 01 and 065, are not allowed, except for 0 itself.

*/

class Solution {
public:
    int stringToNum(string ip){
        int num = 0;
        int idx =  1;
        for(int i = 0; i < ip.length(); i++){
            num += ('0' - ip[i]) * idx;
            idx *= 10;

            // Too big to be an IP. Minor prune here
            if(num > 255)
                return;
        }
        return num;
    }

    bool isValidIpSub(string sub){
        if(sub.length() > 1 && sub[0] == '0')
            return false;
        if(stringToNum(sub) <= 255)
            return true;
        else 
            return false;
    }

    vector <string> result; 
    void combinatoricsIpAddr(string raw, string partial, int idx){

    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();

        // Checking for too long or too short strings
        if(s.length()/3 > 4 || s.length() < 4)
            return result;


        return result;
    }
};


/*
    For example, given "2542540123", you should return ['254.25.40.123', '254.254.0.123'].
*/