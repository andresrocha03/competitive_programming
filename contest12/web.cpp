#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define NODES 101  // Define the maximum number of nodes

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V = 100, E, u, v, w, dist[NODES][NODES], c=1;
    int sum, big;
     
    while (true) {     
        set<int> s;
        cin >> u >> v;

        if (u == v) {
            break;
        }

        for (int i = 1; i <= V; i++) {
            for (int j = 0; j <= V; j++) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        dist[u][v] = 1;
        s.insert(u);
        s.insert(v);
        while (true) {
            cin >> u >> v;
            if (u == v) {
                break;
            }
            else {
                s.insert(u);
                s.insert(v);
                dist[u][v] = 1;
            }
        }
            
        // Floyd-Warshall algorithm
        for (int k = 1; k <= V; k++) {
            for (int i = 1; i <= V; i++) {
                for (int j = 1; j <= V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = (dist[i][j] < dist[i][k] + dist[k][j]) ? dist[i][j] : (dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Printing the distance matrix
        sum = 0;
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][j] != INF && dist[i][j] != 0) {
                    //cout << i << j << dist[i][j] <<  "\n";
                    sum += dist[i][j];
                }
            }
        }

        int size = s.size();
        size *= (size-1);
        float average = float(sum)/float(size);
        cout << "Case " << c << ": average length between pages = " << fixed << setprecision(3) << average<< " clicks" << "\n";
        
        c++;
    }

    return 0;
}
