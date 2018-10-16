#include "./../../Include/Common.h"
/* 
    599. Minimum Index Sum of Two Lists

    https://leetcode.com/problems/minimum-index-sum-of-two-lists/

*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap; 
        for(int i = 0; i <  list1.size(); i++) {
            hashmap[list1[i]] = i; 
        }   
        
        int min = INT_MAX;
        vector<string> res;
        for(int i = 0; i <  list2.size(); i++) {
            // Only if you found list1 in list2, count is used to check if the key exists 
            if(hashmap.count(list2[i])){
                hashmap[list2[i]] += i; 
                if(hashmap[list2[i]] < min){
                    min = hashmap[list2[i]]; 
                    res.clear();
                    res.push_back(list2[i]);
                } else if(hashmap[list2[i]] == min){
                    res.push_back(list2[i]);
                }
            }
        }   
        return res;
    }
};