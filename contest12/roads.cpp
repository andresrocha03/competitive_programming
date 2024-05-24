#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define NODES 301  // Define the maximum number of nodes

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V = 300, u, v, w, dist[NODES][NODES], c=1;
    int n, sum, big, k;
     
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w;
            dist[i][j] = w;
        }
    }

    cin >> k;

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = (dist[i][j] < dist[i][k] + dist[k][j]) ? dist[i][j] : (dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i=0; i<k; i++) { 

        cin >> u >> v >> w;
       
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
           
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i != j) {
                        if (dist[i][u] + w + dist[v][j] < dist[i][j]) {
                        dist[i][j] = w; 
                        dist[j][i] = w;
                        cout << "i: " << i << "j: " << j << "u: " << u << "v " << v << "\n";
                        cout << "HEY\n";
                        }
                        if (dist[i][v] + w + dist[u][j] < dist[i][j]) {
                            dist[i][j] = w; 
                            dist[j][i] = w;
                             cout << "i: " << i << "j: " << j << "u: " << u << "v " << v << "\n";
                            cout << "HEY\n";
                        }

                    }

                }
                for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << dist[i][j] << " ";
                }cout<< "\n";}
            }
        }
            
            
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                sum += dist[i][j];
            }
        }
        cout << sum << " \n";

    }

    
    
       
        
        
    

    return 0;
}
