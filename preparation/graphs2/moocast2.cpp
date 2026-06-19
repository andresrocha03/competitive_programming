#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1000 + 1;

int x[MAXN], y[MAXN];
vector<pair<ll, pair<ll, ll>>> edges;

int repr[MAXN];

ll sq(ll a) { return a*a; }

ll dist(ll i, ll j) { return sq(x[i] - x[j]) + sq(y[i] - y[j]); }

int find (int a) {
    if (repr[a] < 0) {
        return a;
    }
    return repr[a] = find(repr[a]); //path compression
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return false;

    if (repr[a] > repr[b]) swap(a, b);

    repr[a] += repr[b];
    repr[b] = a;
    return true;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //read input
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    } 

    // build edges
    for (int i=0;i<N; i++) {
        for (int j=i+1;j<N; j++) {
            edges.push_back({dist(i,j), {i,j}});
        }
    }

    //kruskal algo
    fill(repr,repr+MAXN,-1); // Initialize union-find
    sort(edges.begin(), edges.end());
    
    ll mew = -1;
    for (auto [w, e]:edges){
        if (unite(e.first, e.second)) {
            mew = w;
        }
    }
    cout << mew;

    return 0;
}