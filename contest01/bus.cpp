#include <bits/stdc++.h>

using namespace std;

int arr[405][4];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cont=0;
    cin >> n >> m;

    for (int i=0;i<n;i++) {
        cont++;
        arr[i][0] = cont;
        if (cont == m) break;
        cont++;
        arr[i][3] = cont;
        if (cont == m) break;
    }

    for (int i=0;i<n;i++) {
        if (cont == m) break;
        cont++;
        arr[i][1] = cont;
        if (cont == m) break;
        cont++;
        arr[i][2] = cont;
    }

    for (int i=0; i<n; i++) {
        if (arr[i][1] != 0) {cout << arr[i][1] << " "; cont--;}
        if (cont == 0) break;
        cout << arr[i][0] << " ";
        cont--;
        if (cont == 0) break;
        if (arr[i][2] != 0) {cout << arr[i][2] << " "; cont--;} 
        if (cont == 0) break;
        cout << arr[i][3] << " ";
        cont--;
        if (cont == 0) break;
    }



}