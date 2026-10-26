#problem: Given a string with digits, return the number of ways to decode it. The mapping is 'A' -> 1, 'B' -> 2, ..., 'Z' -> 26.
#Sol: We use memoization to compute states rather than exploring repeated subtrees in the recursion tree.

class Solution:
    def dfs(self, i, dp, s): 
        if (i == len(s)):
            return 1
        
        if (dp[i] != -1):
            return dp[i]
        
        dp[i] = 0
        if s[i] != '0' and i+1<=len(s): #we can explore i alone
            dp[i] += self.dfs(i+1,dp,s)
        
        if i + 1 < len(s) and "10" <= s[i:i+2] <= "26":
            dp[i] += self.dfs(i + 2, dp, s)

        return dp[i]

    def numDecodings(self, s: str) -> int:
        if s[0] =='0':
            return 0
        dp = [-1]*len(s)
        print(dp)
        return self.dfs(0,dp,s)