# include <bits/stdc++.h>
using namespace std;

typedef vector<vector<double>> adj_list;

const double INF = 1e9;

bool arbitrage (int V, adj_list &dist) {
    for (int k=0; k<V; k++) {
        for (int u=0;u<V;u++) {
            for (int v=0;v<V; v++) {
                double candidate = dist[u][k] * dist[k][v];
                if (candidate < dist[u][v]) dist[u][v] = candidate; 
            }
        }
    }
    for (int u=0; u<V; u++) {
        if (dist[u][u] < 1) {
            return true;
        }
    }
    return false;
}


int main() {
    int V,E;
    cin >> V;
    while (V != 0) {
        // cout << V << "\n";
        adj_list dist(V, vector<double>(V,INF));
        map<string,int> id;
        for (int i=0; i<V; i++) {
            string name;
            cin >> name;
            id[name] = i;
            dist[i][i] = 1.0;
        }
        cin >> E;
        while (E--) {
            string orig, dest;
            unsigned num, denom;
            cin >> orig >> dest;
            char colon;
            // cin >> orig >> colon >>  dest;
            scanf("%u:%u\n",&num,&denom);
            dist[id[orig]][id[dest]] = (num*1.0)/denom;
        } 
        if (arbitrage(V,dist)) cout << "Arbitrage\n";
        else cout << "Ok\n";
        cin >> V;
    }
    // cout << V << "\n";
    return 0;
}