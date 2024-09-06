#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;

    cin >> t;

    while (t--) {
        cin >> n;
        int c = 0;
        for (int i=1; i<=sqrt(n); i++) {
            if (n%i==0) {
                if (n%(n/i)==0 && i != n/i) {
                    c += 2;
                }
                else  c ++;
            };
        }
        cout << c << "\n";
    }
    

    return 0;
}