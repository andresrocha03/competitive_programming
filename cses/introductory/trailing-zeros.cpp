#include <bits/stdc++.h>
using namespace std;


int main() {
    int x = 5;
    int ans = 0;

    int n; cin >> n;

    while (x <= n){
        ans += n/x;
        x *= 5;
    }
    cout << ans << "\n";

    return 0;
}