using namespace std;
#include <bits/stdc++.h>

//a funcao abaixo foi retirada dos slides da aula
struct point {
    long long x, y;
};

// verificar se três pontos fazem uma volta para a esquerda
bool ccw(const point& a, const point& b, const point& c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL*(b.y - a.y) * (c.x - a.x) > 0;
}

// verificar se o polígono é convexo
bool isConvex(const std::vector<point>& P) {
    int sz = (int)P.size();

    //determina a direção da primeira curva
    bool isLeft = ccw(P[0], P[1], P[2]);

    //se todas as curvas seguem a mesma direção
    for (int i = 1; i < sz-1; i++) {
        if (ccw(P[i], P[(i + 1)], P[(i + 2)==sz ? 1 : (i+2)]) != isLeft) {
            return false; // se há uma curva na direção oposta, o polígono é côncavo
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    while (n) {
        int aux =n;
        long long x,y;
        vector<point> poly;
        while (aux--) {
            cin >> x >> y;
            point pin = {x,y};
            poly.push_back(pin);
        }
        poly.push_back(poly[0]);
        if (!isConvex(poly)) cout << "Yes\n";
        else cout << "No\n";
        cin >> n;
    }
}