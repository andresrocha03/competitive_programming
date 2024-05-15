#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v;
    int n,f,a = -1,b = -1,c = -1,triangle=0;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> f;
        v.push_back(f);
    }
    for (int i=1; i<=n; i++) {
        a = i;
        b = v[i-1];
        c = v[b-1];
        if (v[c-1] == a) {
            triangle = 1;
        }
    }

    if (triangle) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }


}