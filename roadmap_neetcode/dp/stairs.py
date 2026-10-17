#Problem: Given an integer n, return the number of distinct ways that I can go from 0 to n, summing, at each step 1 or 2
#Solution: Consider a vector dp, where dp[i] = dp[i-1]+dp[i-2]; position i stores the number of ways to reach i.

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0,1,2]
        for i in range(3,n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]