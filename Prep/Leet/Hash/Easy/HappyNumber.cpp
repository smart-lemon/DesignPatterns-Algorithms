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
            sum = 0;
            hashset.insert(number);

            while(number) {
                int res = number % 10;
                number = number / 10;
                sum += (res * res);
            }
            
            if(sum == 1)
                return true;
            
            if(hashset.find(sum) != hashset.end())
                return false;

            number = sum;
        }
        return false;
    }

    // Using fact all numbers in [2, 6] are not happy 
    // (and all not happy numbers end on a cycle that hits this interval):
    bool isHappyFloydCycleDetection(int n) {
    while(n > 6){
        int next = 0;
        while(n){
                next += (n % 10) * (n % 10); 
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};