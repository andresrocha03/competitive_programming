#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,digits=0, aux, res;
    cin >>  n;
    aux = n;
    while (aux) {
        aux /= 10;
        digits++;
    }
   
    res = digits*(n+1);
    //cout << res << "\n";

    long long sub = 1;
    //subtrair potencias de 10 com os expoentes de 0 até digits-1
    for (int i=0; i < digits; i++) {
        res -= sub;
        sub *= 10;
    }

    cout << res;

    return 0;
}