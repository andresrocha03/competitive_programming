#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int pts[MAXN];
int ptsava[MAXN];
vector<int> adj[MAXN];


pair<int,int> val(int cur, int par) {

    int trav = 0, pot = 0;

    for (int c:adj[cur]) {
        if (c != par) {
            pair<int ,int> sub = val(c, cur);
            trav += sub.first;
            int add = min(ptsava[cur], sub.first-sub.second);
            ptsava[cur] -= add;
            pot += sub.second+add;
        }
    }

    if (trav==0) {
        trav=1;
        pot = min(1, ptsava[cur]);
        if (pot) ptsava[cur]--;
    }

    return {trav, pot};

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i=0;i<n;i++) {
        cin >> pts[i];
    }

    for (int i=1;i<n;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // count leafs and check how many potions are available
    int trav=0;
    for (int i=2;i<=n;i++) {
        if (adj[i].size() == 1) {
            ptsava[pts[trav++]]++;
        }
    }

    cout << val(1,0).second <<"\n";

    return 0;
}