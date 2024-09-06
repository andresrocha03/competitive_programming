import math
#a funcao abaixo foi obtido no link https://www.geeksforgeeks.org/python-program-for-efficient-program-to-print-all-prime-factors-of-a-given-number/
##a funcao foi alterada para satisfazer o problema
def prime(n):     
    counter = -1
    factor = []
    power = []
    # Print the number of two's that divide n
    if n%2==0:
        counter += 1
        factor.append(0)
        power.append(0)
        factor[counter] = 2
        while n % 2 == 0:
            power[counter] += 1
            n = n // 2
    
    # n must be odd at this point
    # so a skip of 2 ( i = i + 2) can be used
    for i in range(3,int(math.sqrt(n))+1,2):
        # while i divides n , print i ad divide n
        if n % i==0:
            counter += 1
            factor.append(0)
            power.append(0)
            factor[counter] = i
            while n % i== 0:
                power[counter] += 1
                n = n // i
    # Condition if n is a prime
    # number greater than 2
    if n > 2:
        counter+=1
        factor.append(0)
        power.append(0)
        factor[counter] = n
        power[counter] = 1
    for p,f,index in zip(factor, power, range(len(factor))):
        print(f"{factor[index]}^{power[index]} ", end='')
    print()


numbers = []
n = int(input())
while (n!=0):
    numbers.append(n)
    n = int(input())

for n in numbers:
    prime(n)