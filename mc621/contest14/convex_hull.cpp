#include <bits/stdc++.h>
using namespace std;


#include <vector>
#include <algorithm>
#include <cmath>



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

bool collinear(const point& a, const point& b, const point& c) {
    // Check if three points are collinear using the area of the triangle
    return fabs(1LL*(b.x - a.x) * (c.y - a.y) - 1LL*(b.y - a.y) * (c.x - a.x)) < 1e-9;
}

bool ccw(const point& a, const point& b, const point& c) {
    // Check if three points make a counter-clockwise turn
    return 1LL*(b.x - a.x) * (c.y - a.y) - 1LL*(b.y - a.y) * (c.x - a.x) >= 0;
}

bool angleCmp(const point& a, const point& b) {
    // Angle-sorting function
    if (collinear(pivot, a, b)) {
        // Special case: points are collinear with the pivot
        return dist(pivot, a) < dist(pivot, b); // Closer point comes first
    }
    long long d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    long long d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    double angle1 = atan2(d1y, d1x);
    double angle2 = atan2(d2y, d2x);
    return angle1 < angle2; // Compare angles
}


bool angleCmp2(const point& a, const point& b) {
    // Angle-sorting function
    if (collinear(pivot, a, b)) {
        // Special case: points are collinear with the pivot
        return dist(pivot, a) > dist(pivot, b); // Closer point comes first
    }
    long long d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    long long d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    double angle1 = atan2(d1y, d1x);
    double angle2 = atan2(d2y, d2x);
    return angle1 < angle2; // Compare angles
}


std::vector<point> CH(std::vector<point> P) {
    // The content of P may be reshuffled
    long long n = (long long)P.size();

    // First, find P0 = point with lowest Y and if tie: rightmost X
    long long P0 = 0;
    for (long long i = 1; i < n; i++) {
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) {
            P0 = i;
        }
    }
    // Swap P[P0] with P[0]
    std::swap(P[0], P[P0]);

    // Second, sort points by angle w.r.t. pivot P0
    pivot = P[0]; // Use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // We do not sort P[0]

    int flag=-1;
    for (int i=0; i<P.size()-1; i++) {
        if (P[i+1].y < P[i].y) {
            flag = i + 1;
            break;
        }
    }

    if (flag!= -1) sort(P.begin()+flag,P.end(), angleCmp2);

    // Third, the ccw tests
    std::vector<point> S;
    S.push_back(P[n - 1]);
    S.push_back(P[0]);
    S.push_back(P[1]); // Initial S
    long long i = 2; // Then, we check the rest
    while (i < n) {
        long long j = (long long)S.size() - 1;
        if (ccw(S[j - 1], S[j], P[i])) {
            S.push_back(P[i++]); // Left turn, accept
        } else {
            S.pop_back(); // Or pop the top of S until we have a left turn
        }
    }
    return S; // Return the result
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int aux = n;
    vector<point> points;
    while (aux--) {
        long long x, y;
        cin >> x >> y;
        point pin = {x, y};
        points.push_back(pin);
    }

    // for (int i=0; i<points.size(); i++) {
    //     cout << points[i].x << " " << points[i].y << "\n";
    // }


    vector<point> res = CH(points);
    cout << res.size() -1 << "\n";

    for (long long i=0; i<res.size() - 1; i++) {
        cout << res[i].x << " " << res[i].y << "\n";
    }

    return 0;
}