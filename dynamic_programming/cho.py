def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        array = input().split()
        for i in range(n):
            array[i] = int(array[i])
        trocado = 0
        soma = 0
        for i in range(n-1):
            if(array[i] > array[i+1]) and trocado == 0:
                soma+=1
                trocado = 1
            else:
                trocado = 0
        print(soma)