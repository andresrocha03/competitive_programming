#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        
        if (a==b) { //equal vectors
            cout << "0\n";
            continue;
        }

        int x =0; // #cases a[i] is 1 and b[i] is 0
        for(int i=0; i<n;i++) {
            if (a[i] != b[i]) {
                x += a[i];
            }
        }

        if (accumulate(a.begin(), a.end(), 0) == 0 || accumulate(b.begin(), b.end(), 0) == n) { // impossible cases
            cout << "-1\n";
            continue;
        }

        if (x%2 != 0) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }

    }

    return 0;
}