#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9;  // Use a large number to avoid overflow
using ii = pair<int, int>;
using vii = vector<ii>;

vector<int> dist;
vector<int> pred;

void bellman_ford(int s, int V, vector<vii> AdjList) {
    dist.assign(V, INF);  // Initialize distances to infinity
    pred.assign(V, -1);   // Initialize predecessors to -1
    dist[s] = 0;          // Distance from source to itself is 0

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;  // Relax operation
                    pred[v.first] = u;  // Save predecessor
                }
            }
        }
    }

    for (int j = 0; j < pred.size(); j++) {
        cout  << "pred " << pred[j] << "\n";
    }
    

    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++) {
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second) {  // If this is still possible
                hasNegativeCycle = true;  // Then negative cycle exists!
            }
        }
    }
    
    if (hasNegativeCycle) cout << "possible\n";
    else cout << "not possible\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, tests, i=1, v1, v2, w;

    cin >> tests;

    for (int i=1; i<= tests; i++) {
        cin >> n >> m;
        vector<vii> AdjList (n);
        for (int j=0; j<m; j++) {
            cin >> v1 >> v2 >> w;
            AdjList[v1].push_back(make_pair(v2,w));
        }
        bellman_ford(0,n, AdjList);        
    }

    return 0;
}