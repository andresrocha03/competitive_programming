def func(k, soma, x, dp):
    if dp[k][soma] != -1: return dp[k][soma] 
    if(k == 0):
        if(soma < x):
            dp[k][soma] = 0
            return 0
    
        else:
            dp[k][soma] = 1
            return 1
    else:
        dp[k][soma] = 0
        for i in range(1, 7):
            dp[k][soma] += func(k - 1, soma + i, x, dp)
    
    return dp[k][soma]

def main():
    n, a, b = [int(x) for x in input().split()]
    dp = [[-1 for _ in range(6 * (n + 1))] for _ in range( (n + 1))]
    
    pa = func(n, 0, a, dp)
    dp = [[-1 for _ in range(6 * (n + 1))] for _ in range( (n + 1))]
    
    pb = func(n, 0, b + 1, dp)

    print(f"{(pa-pb)/pow(6,n):.6f}")
main()