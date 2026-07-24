#include <bits/stdc++.h>
using namespace std; 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k, m; cin >> n >> k >> m;

        if (k > m) cout << "NO\n";
        else {
            cout << "YES\n";
            
            for (int i=0;i<n;i++) {
                if (i%k) cout << 1;
                else cout << m-(k-1);
                cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}