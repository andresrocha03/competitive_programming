using namespace std;
#include <bits/stdc++.h>
struct point {
    int x, y;
};

// Função ccw para verificar se três pontos fazem uma volta para a esquerda
bool ccw(point a, point b, point c) {
    // cout << ((a.x - b.x) * (a.y - c.y) - (a.y - b.y) * (a.x - c.x)) << "\n"; 
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x) >= 0;
}

// Função para verificar se um ponto está dentro de um polígono
int inPolygon(const point& pt, const std::vector<point>& P) {
    if ((int)P.size() == 0) return false;
    int inside =1;
    for (int i = 0; i<P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i + 1])) {
        } else {
            inside =0;
            break;
        }
    }
    return inside;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;

    int aux=n;
    vector<point> P;
    while (aux--) {
        int x,y;
        cin >> x >> y;
        point pin = {x,y};
        P.push_back(pin);
    }
    P.push_back(P[0]);
    while (q--) {
        int x,y;
        cin >> x >> y;
        point pin = {x,y};
        if (inPolygon(pin,P)) {
            cout << "D\n";
        }
        else cout << "F\n";
    }
    return 0;
}
