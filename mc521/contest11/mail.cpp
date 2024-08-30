#include <bits/stdc++.h>

using namespace std;

const int INF =1E9;  // Use a large number to avoid overflow
using ii = pair<int, int>;
using vii = vector<ii>;

vector<int> dist;
vector<int> pred;


void dijkstra(int s, int V, int t, int i, vector<vii> AdjList) {
    dist.assign(V, INF);
    pred.assign(V, -1);
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dist[s] = 0;
    pq.push(ii(dist[s], s));

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();  // greedy: get shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;  // check for duplicates

        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];  // all outgoing edges from u
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;  // relax operation
                pred[v.first] = u;  // save predecessor
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    if (dist[t]<INF) {
        cout << "Case #" << i << ": " << dist[t] << "\n";
    }
    else {
        cout << "Case #" << i << ": unreachable" << "\n"; 
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t, tests, i=1, v1, v2, w;

    cin >> tests;

    for (int i=1; i<= tests; i++) {
        cin >> n >> m >> s >> t;
        vector<vii> AdjList (n);
        for (int j=0; j<m; j++) {
            cin >> v1 >> v2 >> w;
            AdjList[v1].push_back(make_pair(v2,w));
            AdjList[v2].push_back(make_pair(v1,w));
        }
        dijkstra(s,n, t, i, AdjList);        
    }

    return 0;
}