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
            }
        }

        // insert at 1 at front
        if(digits[0] > 9){
            digits[0] = 0;
            vector<int>::iterator it;
            it = digits.begin();
            digits.insert(it, 1);   
        }
        return digits;
    }
};