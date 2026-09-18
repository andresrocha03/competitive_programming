#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,y,i=0;
    long long moves=0;
    cin >> n;
    vector<int> v(n);
    while (cin >> y) {
        v[i] = y;
        if (i > 0) {
            if (v[i-1] > v[i]) {
                moves += v[i-1] - v[i];
                v[i] = v[i-1];
            }
        }
        i++;
    }     
    cout << moves << "\n";
}