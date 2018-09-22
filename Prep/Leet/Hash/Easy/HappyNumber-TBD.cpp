#include "./../../Include/Common.h"

/*
    https://leetcode.com/problems/happy-number/

*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> hashset; 
        
        int sum = 0; 
        int number = n;
        while (1) {
            while(number) {
                int res = number % 10;
                number = number / 10;
                
                sum += (res * res);

                if(sum  == 1)
                    return true;
            }
            if(hashset.find(sum) != hashset.end())
                    return false;

            hashset.insert(sum);
        }
        return false;
    }
};