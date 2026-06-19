#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXNM = 2000 + 2;
ll a[MAXNM], b[MAXNM];
ll repr[MAXNM*MAXNM];

vector<pair<ll, pair<ll, ll>>> edges;

ll find(int a) {
    if (repr[a] < 0) return a;
    return repr[a]=find(repr[a]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    if (repr[a] > repr[b]) swap(a,b); 

    repr[a] += repr[b];
    repr[b] = a;
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //input
    int A, B, n, m;
    cin >> A >> B >> n >> m ;
    for (int i=1;i<=n;i++) cin >> a[i];
    a[n+1] = A;
    sort(a, a+n+1);
    for (int i=1;i<=m;i++) cin >> b[i];
    b[m+1] = B;
    sort(b, b+m+1);

    //build graph
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i<n) edges.push_back( {b[j+1] - b[j], {(i*MAXNM + j), ((i+1)*MAXNM + j)}} );
            if (j<m)  edges.push_back( {a[i+1] - a[i], {(i*MAXNM + j), ((i)*MAXNM + j+1)}} );
        }

    }

    //kruskal
    ll sum = 0;
    fill(repr, repr+(MAXNM*MAXNM), -1);
    sort(edges.begin(), edges.end());
    for (auto [w, e]:edges) {
        if (unite(e.first, e.second)) {
            sum += w;
        }
    }

    cout << sum;

    return 0;
}