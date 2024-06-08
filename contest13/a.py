def div(x):
    res = 0
    for i in range(1, x+1):
        if x % i == 0:
            res += 1
    return res

for i in range(15):
    print(i, div(2**i))