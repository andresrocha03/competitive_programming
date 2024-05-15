#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,k,i,x,p;
    cin >> t;
    while(t--) {
    cin >> n >> k;
    for(i=p=1;i<=n;i++) {
        cin >> x;
        if (x==p) {
            p++;
        }
    }
    cout << (n-p+k)/k << "\n";
    }
}