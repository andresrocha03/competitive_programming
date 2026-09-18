#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;

    int res = 1;
    while (n--) {
        res = (res*2)%(1000000007);
    }    

    cout << res << "\n"; 

    return 0;
}