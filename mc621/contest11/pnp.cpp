#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n==0||n==1||n==2) cout << 0;
    else cout << n-2;    


    return 0;
}