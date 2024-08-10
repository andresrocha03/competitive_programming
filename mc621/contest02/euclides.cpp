#include <bits/stdc++.h>
using namespace std;

unsigned long long res=0, aux=0;

void solve(long long a, long long b) {
    unsigned long long c;
    res = 0;
    while (a != 0 && b !=0) {
        if (a>b) {
            aux = a/b;
            a %= b;
            res += aux;
            if (a==0) res--;
        }   
        else {
            aux = b/a;
            b %= a;
            res += aux;
            if (b==0) res--;
        } 
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long t, a, b;
    
    cin >> t;

    while (t--) {
        cin >> a >> b;
        if (a == b) cout << 0 << "\n";
        else solve(a,b);

    }


    return 0;
}