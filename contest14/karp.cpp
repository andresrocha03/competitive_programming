#include <bits/stdc++.h>
using namespace std;

#define MAX_V 502 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
#define INF LLONG_MAX // Use a very large value for infinity
typedef vector<int> vi;

// Global variables
long long res[MAX_V][MAX_V], mf, f, s, t;
long long flow[MAX_V][MAX_V];

vi p;
vector<vi> AdjList;
vector<pair<int,int>> used;

void augment(int v, long long minEdge) {
    if (v == s) {
        f = minEdge; 
        return; // Record minEdge in a global variable f
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v])); // Recursive call
        
        if (f > 0) { // Ensure that we only update if a valid path is found
            res[p[v]][v] -= f; 
            res[v][p[v]] += f; // Update residual capacities

            flow[p[v]][v] += f; 
            flow[v][p[v]] -= f; // Update actual flow
        }
    }
}

int main() {
    int V, E, u, v, w;
    cin >> V >> E >> s >> t;
    memset(res, 0, sizeof res);
    memset(flow, 0, sizeof flow);
    AdjList.assign(V, vi());

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        res[u][v] = w;
        //res[v][u] = w; // Uncomment if the graph is undirected
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    mf = 0;
    while (1) { // Main loop
        f = 0;
        vector<bool> vis(V, false);
        queue<int> q; q.push(s);
        vis[s] = true;
        p.assign(V, -1);
        while (!q.empty()) {
            int u = q.front(); q.pop(); 
            if (u == t) break;
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (res[u][v] > 0 && !vis[v]) {
                    vis[v] = true;         
                    q.push(v); 
                    p[v] = u;
                }
            }
        }
        augment(t, INF);
        if (f == 0) break;
        mf += f;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (flow[i][j] > 0) {
                used.push_back(make_pair(i, j));
            }
        }
    }

    cout << V << " " << mf << " " << used.size() << "\n"; // This is the max flow value
    
    for (const auto& edge : used) {
        cout << edge.first << " " << edge.second << " " << flow[edge.first][edge.second] << "\n";
    }
    return 0;
}
