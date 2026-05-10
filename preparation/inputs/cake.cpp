#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll cw;
    ll n;

    cin >> cw;
    cin >> n;

    ll pw;
    ll pl;
    ll area = 0;
    for (int i=0;i<n; i++) {
        cin >> pw >> pl;
        area += (pw*pl);
    }

    cout << (area/cw);

    return 0;
}