from collections import OrderedDict

'''

2053. Kth Distinct String 
https://leetcode.com/problems/kth-distinct-string-in-an-array/

'''

class Solution:

    def kthDistinct(self, arr, k) -> str:
        non_unique_map = OrderedDict()
        result = ""

        for item in arr:
            if item not in non_unique_map.keys():
                non_unique_map[item] = 1
            else:
                non_unique_map[item] = non_unique_map[item] + 1

        for keys in non_unique_map.keys():
            if non_unique_map[keys] == 1:
                k = k - 1
            if k == 0:
                result = keys

        i = 0
        for item in non_unique_map:
            if non_unique_map[item] == 1:
                i = i + 1

        return result
