#include "./../../Include/Common.h"

/*
    Design a data structure that supports all insert(), remove() 
    and getRandom() operations in average O(1) time.

    https://leetcode.com/problems/insert-delete-getrandom-o1
*/


class RandomizedSet {
    unordered_map<int, int> hashmap; 
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashmap.find(val) == hashmap.end()){
            nums.push_back(val);
            hashmap[val] = nums.size() - 1;
            return true;
        } else {
            return false; 
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
         if(hashmap.find(val) != hashmap.end()){
            int last = nums.back();
            nums[hashmap[val]] = last; // Put last element where val used to be
            hashmap[last] = hashmap[val]; 
            nums.pop_back();
            hashmap.erase(val);
            return true;
        } else {
            return false; 
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       return nums[rand() % nums.size()];
    }
};
