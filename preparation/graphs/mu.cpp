#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
int x[MAXN];
int y[MAXN];
int p[MAXN];
int n;
int cnt=0;

bool seen[MAXN];

int sq(int a) {
    return a*a;
}

void dfs(int s) {
    if (seen[s]) return;
    seen[s] = true;
    cnt++;

    for (int i=0;i<n;i++) {
        int dist2 = sq(x[i] - x[s]) + sq(y[i]-y[s]);
        int p2 = sq(p[s]);
        if (p2 >= dist2) {
            dfs(i);
        }
    }

}

int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> x[i] >> y[i] >> p[i];
    }

    int best = 0;
    for (int c=0;c<n;c++) {
        fill(seen, seen+n, false);
        cnt =0;
        dfs(c);
        best = max(best, cnt);
    }

    cout << best;

}