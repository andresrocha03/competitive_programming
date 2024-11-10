#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n;

    cin >> n >> m;

    long long greater = 1;
    for (long long i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            if (i * n <= m) {
                greater = max(greater, i);
            }
            if ((m / i) * n <= m) {
                greater = max(greater, m / i);
            }
        }
    }

    cout << greater << "\n";
    return 0;
}