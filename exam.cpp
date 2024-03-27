#include <bits/stdc++.h>

using namespace std;




int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k, value;
    vector<int> v;
    set<int> s;
    

    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n >> k;
        for (int j=0; j<n; j++) {
            cin >> value;
            s.insert(value);
            v.push_back(value);
        }


    }

}