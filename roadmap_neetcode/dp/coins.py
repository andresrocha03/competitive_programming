# Problem: Given a list of coins and an amount, return minimum number of coins to get the amount.
# Sol: We use memoization to iterate through all quantities from 0 to amount and  fill the dp array with min number of coins to reach that state

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        dp = [-1]*(amount+1)
        coins.sort()
        dp[0] = 0

        for i in range(len(dp)):
            if (dp[i] == -1):
                res = 10 ** 4 + 1
                for c in coins:
                    if (i>=c and dp[i-c] != -1):
                        res = min(res, dp[i-c]+1)
                if (res != 10 ** 4 + 1):
                    dp[i] = res
        
        return dp[amount]