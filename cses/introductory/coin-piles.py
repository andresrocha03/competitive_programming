t = int(input())

while (t):
    a, b = map(int, input().split())
    t -= 1

    if (a > b):
        a, b = b, a

    if ((a+b)%3 == 0 and (a*2 >= b)):
        print("YES")
    else:
        print("NO")
