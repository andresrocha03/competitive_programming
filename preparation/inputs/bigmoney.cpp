#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i;
    long long d;

    long long ri = 0;
    long long rd = 0;
    
    while (scanf("%lld.%lld", &i, &d) != EOF) {
        ri += i;
        rd += d;
    }

    ri += (rd/100);
    rd %= 100;

    cout << ri << "." << setw(2) << setfill('0') << rd; 
 
    return 0;
}