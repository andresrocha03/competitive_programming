#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    char d[1001];
    ll p, q; 
    ll t = 0;

    while (true) {
        scanf("%[^\n]\n",d);
        string sd(d);
        if (sd == "TOTAL") break;
        scanf("%lld %lld\n",&p, &q);
        t += p*q;
    }

    scanf("%lld", &p);
    if (p > t) cout << "PROTEST";
    else cout <<"PAY";

    return 0;
}