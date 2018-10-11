#include "./../../../../Include/Common.h"

/*
    347. Top K Frequent Elements
    Return the k most frequent elements. (In O(n log n) runtime)
    
    https://leetcode.com/problems/top-k-frequent-elements
*/

class Solution {
   
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap; 

        for(auto item : nums){
            hashmap[item]++; 
        }

        vector<int> result; 
        priority_queue<int, vector<int>, greater<int>> max_k;

        for(auto & items : hashmap) {
            // Add the frequencies to the queue
            max_k.push(items.second);
            // Size of the min heap is maintained at equal to or below k
            while(max_k.size() > k) 
                max_k.pop();
        }

        // Only if the item in hashmap has a frequency that is >= that  of the smallest in the k-min heap
        for(auto & item : hashmap) {
            if(item.second >= max_k.top()) 
                result.push_back(item.first);
        }
       
        return result;
    }
};