#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define NODES 301  // Define the maximum number of nodes

int minDistance(int dist[], bool sptSet[], int n)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 1; v <= n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


int distd[NODES]; 

void dijkstra(int graph[NODES][NODES], int src, int n)
{
    bool sptSet[n]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 1; i <=n; i++)
        distd[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    distd[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(distd, sptSet, n);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 1; v <= n; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && distd[u] != INT_MAX
                && distd[u] + graph[u][v] < distd[v])
                distd[v] = distd[u] + graph[u][v];
    }
}


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


    for (int i=0; i<k; i++) { 

        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
            for (int vertex = 1; vertex <= n; vertex ++) {
                dijkstra(dist, vertex, n);
            }
            
        }
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                sum += dist[i][j];
            }
        }
        cout << sum << " ";

    }

    
    
       
        
        
    

    return 0;
}
