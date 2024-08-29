#include <stdio.h>
#include <string.h>

// Função de utilidade que retorna o máximo entre dois inteiros
int max(int a, int b) { 
    return (a > b) ? a : b; 
}

// Matriz de DP declarada como variável global
int z[2001][2001];

// Retorna o valor máximo que pode ser colocado em uma mochila de capacidade W
int knapSack(int W, int wei[], int c[], int n) {
    if (z[n][W] > -1) {
        return z[n][W]; // valor já calculado
    }
    if (n == 0 || W == 0) { // Caso base
        z[n][W] = 0;
        return 0;
    }
    // Se o peso do n-ésimo item for maior que a capacidade da mochila W
    // então este item não pode ser incluído na solução ótima
    if (wei[n - 1] > W) {
        z[n][W] = knapSack(W, wei, c, n - 1);
    } else {
        // Retorna o máximo entre dois casos: com e sem o n-ésimo item
        z[n][W] = max(c[n - 1] + knapSack(W - wei[n - 1], wei, c, n - 1),
                      knapSack(W, wei, c, n - 1));
    }
    
    return z[n][W];
}


int main () {
    int W, n;

    memset(z,(-1),2001*2001*sizeof(int));

    scanf("%d %d",&W, &n);
    
    int weight[n], cost[n];

    for (int i=0; i<n; i++) {
        scanf("%d %d",&weight[i], &cost[i]);
    }

    int answer = knapSack(W, weight, cost, n);
    printf("%d",answer);

}