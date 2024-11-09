import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


#O código abaixo foi retirado dos slides da aula e adaptado para python
def area(P):
    result = 0
    for i in range(len(P) - 1):
        x1, y1 = P[i].x, P[i].y
        x2, y2 = P[i + 1].x, P[i + 1].y
        result += (x1 * y2 - x2 * y1)
    return abs(result) 

def main():
    n = int(input())
    P = []

    for _ in range(n):
        a, b = map(int, input().split())
        P.append(Point(a, b))
    
    P.append(P[0])
    print(area(P))

main()