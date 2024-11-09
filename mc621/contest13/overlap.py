
def overlap(ret1, ret2):
    
    if (ret1[0] <= ret2[0] <=  ret1[2]):
        if (ret1[1] <= ret2[1] <= ret1[2]):
            return ret2[0], ret2[1], ret1[2], ret1[3]
        elif (ret2[1] <= ret1[1] <= ret2[2]):
            return ret2[0], ret1[1], ret1[2], ret2[3]
    
    elif (ret1[0] <= ret2[2] <=  ret1[2]):
        if (ret1[1] <= ret2[3] <= ret1[3]):
            return ret1[0], ret1[1], ret2[2], ret2[3]
        elif (ret2[1] <= ret1[3] <= ret2[2]):
            return ret1[0], ret2[1], ret2[2], ret1[3]
        
    elif (ret2[0] == ret1[0] and ret2[1] == ret1[1]):
        if (ret2[2] == ret1[2] and ret2[3]==ret2[3]):
            return ret1[0], ret1[1], ret1[2], ret1[3]

    return -1,-1,-1,-1


def main():
    n = int(input())
    print(n)
    for i in range(n):
        fds = input()

        #Xce, Yce, Xcd, Ycd
        ret1 = [int(i) for i in input().split()]
        ret2 = [int(i) for i in input().split()]

        

        a,b,c,d = overlap(ret1, ret2)

        
        intersection = [a,b,c,d]
        if (intersection[0] != -1):
            print(intersection)
        else:
            print("No Overlap")
        print()


main()

