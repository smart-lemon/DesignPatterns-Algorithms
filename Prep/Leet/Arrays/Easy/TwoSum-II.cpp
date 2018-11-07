#include "./../../../../Include/Common.h"

/*
    167. Two Sum II - Input array is sorted

    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int front = 0, back = numbers.size() - 1;

        while(front != back){
            if(numbers[front] + numbers[back] > target){
                back--;
            } else if (numbers[front] + numbers[back] < target){
                front++;
            } else {
                vector <int> res {numbers[front], numbers[back]};
                return res;
            }
        }
    }
};