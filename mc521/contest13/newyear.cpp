#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, a;
    vector <int> v;
   
    v.push_back(1);
   
    cin >> n >> t;

    for (int i=1; i<n; i++) {
        cin >> a;
        v.push_back(i+a);
    }

    int next = 1;

    for (int i=1; i<n; i++) {
        if (next == n) break;
        next = v[next];
        if (next == t){
            break;
        }
    }

    if (next == t) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}