#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;

    cin >> a;
    while (a) {
        if (a==1) {
            cout << 1;
            continue;
        }
        int lg = log2(a);
        int nearest = pow(2,lg);
        cout << (a - nearest)*2 << "\n";
        cin >> a;
    } 
}