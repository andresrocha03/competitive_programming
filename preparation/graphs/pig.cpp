#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4 +2;
const long long INF = 1e12;

int B,E,P, N, M;
vector<int> adj[MAXN];

vector<long long> bfs(int s) {

    vector<int> todo = {s};
    vector<long long> dist(MAXN, INF);
    dist[s] = 0;

    for (int i=0;i<(int)todo.size();i++) {
        int n = todo[i];
        for (auto v:adj[n]) {
            if (dist[v] > dist[n] +1) {
                dist[v] = dist[n] +1;
                todo.push_back(v);
            }
        }
    }

    return dist;
}


int main() {

    cin >> B >> E >>P>>N>>M;

    for (int i=0;i<M;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<long long> dbessie = bfs(1);
    vector<long long> delsie = bfs(2);
    vector<long long> dboth = bfs(N);

    long long best = INF;
    for (int i=1;i<=N;i++) {
        best = min(best, dbessie[i]*B + delsie[i]*E + dboth[i]*P);
    }

    cout << best << "\n";

    return 0;
}