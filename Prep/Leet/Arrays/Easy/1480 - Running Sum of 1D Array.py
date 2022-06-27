
'''

    1480. Running Sum of 1d Array
    https://leetcode.com/problems/running-sum-of-1d-array/

'''

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        running_sum = 0
        result = list()
        idx = 0

        for i in nums:
            running_sum = running_sum + i
            result.append(running_sum)

        return result

    # With low memory usage
    def runningSumAlt(self, nums: List[int]) -> List[int]:

        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]

        return nums