#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int maxn = 2e5 + 10;

vector<pair<int, int>> adj[maxn];

int lg(int x) {
    int r = 0;
    while (x) {r++; x/=2;}
    return r;
}

struct E {
    int a, b, c;
    bool operator<(E e) {
        return c < e.c;
    }
};

int rep[maxn], sz[maxn];

int find(int x) {
    while (x != rep[x])
        x = rep[x];
    return x;
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    rep[b] = a;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<E> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        c = lg(c) - 1;
        edges.pb({a, b, c});
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    for (int i = 1; i <= n; ++i)
        sz[i] = 1, rep[i] = i;
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto [a, b, c] : edges) {
        if (find(a) != find(b)) {
            join(a, b);
            ans += c;
        }
    }
    cout << ans + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}