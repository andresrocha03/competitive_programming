#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,i=1;
    cin >> n >> k;

    while (n--){
        if (2*i < i+k) i = 2*i;
        else i = i + k;
    }

    cout << i << "\n";

    return 0;

}