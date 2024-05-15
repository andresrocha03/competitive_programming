#include <bits/stdc++.h>
using namespace std;

#define N 1005
int arr[N];
int visitados[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    int i=1;
    int x;

    while(i<=n){
        cin >> x; 
        arr[i] = x;
        i++;    
    }
    
    //percorrer vetor
    
    int atual=1, prox=1;
    for (int k=1; k<=n; k++) {
        atual = k;
        memset(visitados, 0, N);
        visitados[atual] = 1;
        while(true) {
            prox = arr[atual];
            if (visitados[prox]==1) {
                cout << prox << " ";
                break;
            }
            else {
                visitados[prox] = 1;
                atual = prox;
            }

        }
    }

}