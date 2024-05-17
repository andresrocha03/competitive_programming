#include <bits/stdc++.h>

using namespace std;

const int INF =1E9;  // Use a large number to avoid overflow
using ii = pair<int, int>;
using vii = vector<ii>;


vector<int> pred;


int dijkstra(int s, int V, int t, vector<vii> AdjList, vector<int> dist) {
    
    
    return dist[t];
}

int dijkstra2(int s, int V, int t, vector<vii> AdjList, vector<int> dist) {
    int length = -1;
    
    pred.assign(V, -1);
    priority_queue<ii, vector<ii>, greater<ii>> pq;

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
    
    return dist[t];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t, tests, i=1, v1, v2, w, k, length=0, min_length = INF;

    cin >> tests;
    
    for (int i=0; i<tests; i++) {
        cin >> n >> m >> k >> s >> t;
        vector<vii> AdjList (n+1);
        vector<int> dist;
        dist.assign(n+1, INF);

        
        for (int j=0; j<m; j++) {
            cin >> v1 >> v2 >> w;
            AdjList[v1].push_back(make_pair(v2,w));
        }

        int length = -1;
        
        pred.assign(n+1, -1);
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
        
        min_length = dist[t];
       for (int j=0; j<k; j++) {
            vector<int> distCopy(n+1);
            
            for (int l = 0; l<n+1; l++) {
                distCopy[l] = dist[l];
            
            
            }
           
            cin >> v1 >> v2 >> w;
            AdjList[v1].push_back(make_pair(v2,w));
            AdjList[v2].push_back(make_pair(v1,w));
            
    
            int ini;
            if(dist[v1] < dist[v2]) ini = v1;
            else ini = v2;
            pq.push(ii(dist[ini], ini));

            while (!pq.empty()) {
                ii front = pq.top(); pq.pop();  // greedy: get shortest unvisited vertex
                int d = front.first, u = front.second;
                if (d > distCopy[u]) continue;  // check for duplicates

                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];  // all outgoing edges from u
                    if (distCopy[u] + v.second < distCopy[v.first]) {
                        distCopy[v.first] = distCopy[u] + v.second;  // relax operation
                        pred[v.first] = u;  // save predecessor
                        pq.push(ii(distCopy[v.first], v.first));
                    }
                }
            }
                        
            length = distCopy[t];
            if (length < min_length) min_length = length;
            
            
            AdjList[v1].pop_back();
            AdjList[v2].pop_back();
        }      

        if (min_length == INF) cout << -1 << "\n";
        else cout << min_length << "\n";       
    }

    return 0;
}