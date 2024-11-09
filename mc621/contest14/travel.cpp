using namespace std;
#include <bits/stdc++.h>



//o código abaixo foi retirado dos slides da aula e adaptado ao problema
struct point {
    long long x, y;

    bool operator==(const point& other) const {
        return x == other.x && y == other.y;
    }
};

point pivot;

double dist(const point& a, const point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n,k,a,b;
    cin >> t;

    while(t--) {

        vector<point> poin;
        cin >> n >> k >> a >> b;
        while (n--) {
            int x,y;
            cin >> x >> y;
            point pin = {x,y};
            poin.push_back(pin);
        }

        if (a<=k && b<=k ) {
            cout << 0 << "\n";
        }
        else if (a<=k ) {
            long long min=INT_MAX;
            for (int i=0; i<poin.size(); i++) {
                long long d = dist(poin[a-1], poin[i]);
                if ((i != a-1) && d < min && i <= k-1) {
                    min = d;
                }    
            }
            cout << min << "\n";
        }
        else if (b<=k ) {
            long long min=INT_MAX;
            for (int i=0; i<poin.size(); i++) {
                long long d = dist(poin[b-1], poin[i]);
               if ((i != b-1) && (d) < min && i <= k-1) {
                    min = d;
               }
            }
            cout << min << "\n";
        }
        else {

        }

    }



    return 0;
}