#include <bits/stdc++.h>
using namespace std;

//essa funcao foi retirada dos slides da aula
// int gcd(int a, int b) { return b==0 ? a: gcd(b, a%b) ;}

int x,y;

void get_coord(int a, int b, int x, int y) {
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    int x1, y1;
    get_coord(b,a%b,x1,y1);
    x=y1;
    y = x1-y1*(a/b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;

    cin >> a>> b>> c;
    int d = __gcd(abs(a),abs(b));
    if (abs(c)% __gcd(abs(a),abs(b))==0) {
        get_coord(a,b,x,y);
        d  = c/d;
        cout << x*d << y*d;
    }
    else cout << -1;

    return 0;
}