#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1000 + 5;
const int MAXT = 1000 + 5;

vector<pair<int, int>> edges;
ll value[MAXN];
ll dp[2][MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,c;
    cin >> n >> m >> c;

    for (int i=1;i<=n;i++) {
        cin >> value[i];
    }

    int a,b;
    for (int i=0;i<m;i++) {
        cin >> a >> b;
        edges.push_back(make_pair(a,b));
    }

    ll max_profit = 0;
    memset(dp, -1, sizeof dp);
    dp[0][1] = 0;

    for (int t=1; t<MAXT; t++) {
        int p = t%2;
        memset(dp[p], -1, sizeof dp[p]);
        for (auto&e : edges) {
            int a = e.first;
            int b = e.second;
            if (dp[1-p][a] >= 0) {
                dp[p][b] = max(dp[p][b], dp[1-p][a]+value[b]);
            }
        }
        max_profit = max(max_profit, dp[p][1] - c*t*t);
    }

    cout << max_profit;

    return 0;
}