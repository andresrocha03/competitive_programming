#Problem: Given an array of integers, return value of maximum product of a subarray.
#Sol: Keep maximum and minum products of subarrays ending at each index, which is the Kadane's algorithm.

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxi = nums[0]
        mini = nums[0]
        res = nums[0]

        for i in range(1,len(nums)):
            aux_maxi = max(mini*nums[i], maxi*nums[i], nums[i])
            aux_mini = min(mini*nums[i], maxi*nums[i], nums[i])
            maxi = aux_maxi
            mini = aux_mini
            res = max(maxi, res)

        return res

        