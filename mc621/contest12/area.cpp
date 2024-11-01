#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double area(const std::vector<Point>& P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < static_cast<int>(P.size()) - 1; i++) {
        x1 = P[i].x;
        x2 = P[i + 1].x;
        y1 = P[i].y;
        y2 = P[i + 1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return std::fabs(result)/2.0;
}


int main ( ){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<Point> P;
    int n; 
    double a,b;

    cin >> n;

    int aux=n;
    while(aux--) {
        cin >> a>> b;
        Point p1 = {a,b};
        P.push_back(p1);
    }
    P.push_back(P[0]);

    cout << area(P);


    return 0;
}