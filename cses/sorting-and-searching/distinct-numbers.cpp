#include <bits/stdc++.h>
 
using namespace std;
 
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i=0,x,distincts=1;
    cin >> n;
    vector<int> v(n);
    while (i<n) {
        cin >> x;
        v[i] = x;
        i++;
    }
    sort(v.begin(),v.end());
    
    x = v[0];
    
    for (i=0; i<n; i++){
        if (v[i]!=x) {
            distincts += 1;
            x = v[i];
        }
    }
    cout << distincts << "\n";
}