#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, int> a;

    string ani;

    int n; cin >> n;
    
    for (int i=0;i<n;i++) {
        cin >> ani;
        a[ani]++;    
    }

    int i =0;
    for (auto animal:a) {
        if (animal.second > n - animal.second) {
            cout << animal.first;
            i = 1;
            break;
        }
    }

    if (!i) cout << "NONE";

    return 0;
}