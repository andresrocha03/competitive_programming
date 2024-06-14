#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[1000];
        for (int i=0; i<n;i++) {
            cin >> arr[i];
        }
        set<int> twopow;
        int possible = 0;
        for (int i=0; i<n;i++) {
            if (twopow.find(arr[i]) != twopow.end()) {
                cout << "YES" << "\n";
                possible = 1;
                break;
            }   
            twopow.insert(arr[i]);
        }
        if (!possible) {
            cout << "NO" << "\n";
        }
    }

}