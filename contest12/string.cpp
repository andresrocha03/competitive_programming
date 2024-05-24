#include <bits/stdc++.h>

#define INF INT_MAX
#define NODES 500  // Define the maximum number of nodes

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E, u, v, w, dist[NODES][NODES];
    string str1, str2;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }




    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        dist[u][v] = w; // directed graph

    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = (dist[i][j] < dist[i][k] + dist[k][j]) ? dist[i][j] : (dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Printing the distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
