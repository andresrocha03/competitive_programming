#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    vector<int> nek, bra;

    cin >> t;
    while (t--) {
        cin >> n;
        int aux;
        for (int i=0; i<n; i++) {
            cin >> aux;
            nek.push_back(aux);
        }
        for (int i=0; i<n; i++) {
            cin >> aux;
            bra.push_back(aux);
        }
        //solve
        sort(nek.begin(), nek.end());
        sort(bra.begin(), bra.end());
        for (int i=0; i<nek.size(); i++) {
            cout << nek[i] << " ";
        }
        cout << "\n";
        for (int i=0; i<bra.size(); i++) {
            cout << bra[i] << " ";
        }
        cout << "\n";
        nek.clear();
        bra.clear();
    }

    return 0;
}