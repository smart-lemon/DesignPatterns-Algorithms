#include "./../../../../Include/Common.h"

/*
    347. Top K Frequent Elements
    Return the k most frequent elements. (In O(n log n) runtime)
    
    https://leetcode.com/problems/top-k-frequent-elements
*/
 bool compare(pair<int , int> & a, pair<int, int> & b) {
        return a.second > b.second? true : false;
}
class Solution {
   
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap; 

        for(auto item : nums){
            hashmap[item]++; 
        }

        vector<pair<int, int>> list; 

        // O(n)
        for(auto item : hashmap){
            list.push_back(make_pair(item.first, item.second));
        }

        // O(n log(n))
        sort(list.begin(), list.end(), compare);
        
        // O(n)
        int top_k = k, i = 0;
        vector<int> result; 
        while(top_k){
            result.push_back(list[i++].first);
            if(i - 1 >= 0 && i < list.size() && list[i - 1] != list[i]){
                top_k--;
            }
        }
        return result;
    }
};