#include "./../../../../Include/Common.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0){
            digits.push_back(1);
            return digits;
        }

        int n = digits.size();
        digits[n - 1] += 1; 

        for(int i = n - 1; i > 0; i--){
            if(digits[i] > 9){
                digits[i - 1] += 1;
                digits[i] = 0;
            } else {
                break;
            }
        }

        // insert at 1 at front
        if(digits[0] > 9){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);   
        }
        return digits;
    }
};

vector<int> plusOneShorter(vector<int>& digits) {
    for(int i = digits.size() - 1; i >= 0; i--) {
        if (++digits[i] %= 10)
            return digits;
    }
    
    digits[0] = 1;
    digits.push_back(0);

    return digits;
}