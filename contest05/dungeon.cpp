#include <bits/stdc++.h>

using namespace std; 

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,a,b ,c;
    cin >> t;
    while (t--) {
        cin >> a>> b>> c;
        if ((a+b+c)%9 == 0 && a >= (a+b+c)/9 && b>= (a+b+c)/9 && c >= (a+b+c)/9) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}
