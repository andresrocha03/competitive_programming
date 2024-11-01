
#include <bits/stdc++.h>

using namespace std;

// o codigo abaixo foi retirado de 
//https://github.com/luccanunes/algos/blob/master/convex-hull.cpp
// e adaptado ao probelma

struct P {
	long long x, y;
	void read() {
		scanf("%d%d", &x, &y);
	}
	P operator-(const P& p) const {
		return P{x - p.x, y - p.y};
	}
	void operator-=(const P& p) {
		x -= p.x;
		y -= p.y;
	}
	long long int operator*(const P& p) const {
		return (long long int)(x*p.y) - (long long int)(p.x*y);
	}
	long long int triangle(const P& a, const P& b) const {
		return (a - *this) * (b - *this);
	}
	bool operator<(const P& p) const {
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<P> points(n);
	for (P& p : points)
		p.read();
	sort(points.begin(), points.end());
	vector<P> hull;
	for (int rep = 0; rep < 2; rep++) {
		const int s = hull.size();
		for (P c : points) {
			while (hull.size() - s >= 2) {
				P a = hull.end()[-2], b = hull.end()[-1];
				if (a.triangle(b, c) <= 0) break; // c to the right of b | could be <= 0
				hull.pop_back();
			}
			hull.push_back(c);
		}	
		hull.pop_back();
		reverse(points.begin(), points.end());
	}
    printf("%d\n", hull.size());
	for (P p : hull)
		printf("%d %d\n", p.x, p.y);
	return 0;
}