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
        int tens =  1;
        for(int i = 0; i < ip.length(); i++){
            num += (ip[i] - '0') * tens;
            tens *= 10;

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

    void combinatoricsIpAddr(const string raw, string partial, int idx, int subIdx, int slot){
        if(idx > raw.length() || idx + subIdx >= raw.length()){
            return;
        }

        if(idx + subIdx == raw.length() - 1){
            // A proper IP address
            partial.append(".");
            partial.append(raw.substr(idx, idx + subIdx));
            result.push_back(partial);
            return;
        }

        for(; slot <= 4; slot++){
            combinatoricsIpAddr(raw, partial);
        }
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


Each part of an IP address can be one, two, or three digits long. 
A valid part can be either a single digit, a two-digit number between 10 and 99, 
or a three-digit number between 100 and 255. For the input "2542540123", 
for example, we can either begin with "2", "25", or "254". Once we choose one of these, 
we can have up to three valid options for the second part. For example, 
if we started with "2", our next part could either be "5" or "54".

These choices can be represented in a tree, as follows:

               /            |         \
             /              |           \
           2                25          254
        /  |             /   |           |
      /    |           /     |           |
    5     54         4      40           0
  / | \  / | \     / | \   / | \       / | \

At each level of the tree, we find the valid parts that start with the first one, 
two, or three digits of our string. For each of these parts, we add it to our 
potential solution and recursively find the next valid parts in the remainder 
of the string. Once we reach the fourth level of the tree (meaning we have 
generated four valid parts to our IP address), and we have used all the characters 
in our input, we have found a solution. This kind of algorithm is called iterative
deepening depth-first search (IDS).

The time complexity of IDS is O(bd), where b is the branching factor
and d is the tree depth. Here b = 3 and d = 4.

*/