#Problem: Given an arary of costs where index i is the cost of leaving position i, determine the min cost to go from the start position to past the last one
#Solution: Use a cost array to store the min cost of reaching a certain position i. Dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0]*(len(cost)+1)

        for i in range(2, len(dp)): #we may pass the last position n by 1, if we move 2 steps from n-1 or 1 from n 
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1])

        return dp[len(cost)]