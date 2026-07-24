#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    if (is_sorted(a.begin(), a.end())) {
        cout << "0\n";
        return;
    }

    for (int x=0;;x++) {
        int maxi = -1; //maximum so far
        bool check = true;

        for (int j=0; j* (1 << (x+1)) < n; j++) {
            int curr_maxi = -1;
            for (int i=0; j* (1 << (x+1)) + i < n && i < (1 << x+1); i++) {
                int aux = a[j * (1 << (x+1)) + i];
                check = check && (maxi <= aux);
                curr_maxi = max(curr_maxi, aux);
            }
            maxi = max(maxi, curr_maxi);
        }

        if (check) {
            cout << (1<<x) << "\n";
            return;
        }


    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}