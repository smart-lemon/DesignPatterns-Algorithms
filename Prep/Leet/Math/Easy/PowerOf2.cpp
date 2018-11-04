/*
     https://leetcode.com/problems/power-of-two/
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        
        while(n % 2 == 0){
            n = n/2;
        }

        return (n == 1);
    }

    // Pay attention to  0 and power of two means only one bit is 1
    bool isPowerOfTwoBetter(int n) {
        return n > 0 && !(n & (n - 1));
    }
    /*
        n = 2 ^ 0 = 1 = 0b0000...00000001, and (n - 1) = 0 = 0b0000...0000.
        n = 2 ^ 1 = 2 = 0b0000...00000010, and (n - 1) = 1 = 0b0000...0001.
        n = 2 ^ 2 = 4 = 0b0000...00000100, and (n - 1) = 3 = 0b0000...0011.
    */
};