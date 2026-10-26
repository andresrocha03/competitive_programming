#Problem: Given a list of integers, we need to selct the subset with biggest sum, but we cannot select ajacent elements. Also, first and last list elements are adjacent.
#Sol: We use dp to solve bottom up. We consider the scenario when robbing house 0 and not robbing house 0 and build different arrays for each scenario. Finally we go through dp, analyzing if putting house will benefit the sum.

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        elif len(nums) == 3:
            return max(nums[2],nums[0],nums[1])
        
        dp0 = [0]*len(nums)
        dp0[0] = nums[0]
        dp0[1] = nums[0]
        for i in range(2,(len(dp0)-1)):
            dp0[i] = max(dp0[i-1], dp0[i-2]+nums[i])
        dp0[-1] = dp0[len(dp0)-2]

        dp1 = [0]*len(nums)
        dp1[1] = nums[1]
        for i in range(2,len(dp0)):
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i])
        
        return max(dp0[-1], dp1[-1])