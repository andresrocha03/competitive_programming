#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<ll,ll> cost;

const ll MAXN = 1e3 +1;
const ll oo = 1e18;

vector<pair<int,cost>> adj[MAXN];
cost dist[MAXN];

cost add(cost a, cost b) {return cost(a.first+b.first, a.second+b.second);}

int main() {
    int a,b,n; cin >> a >> b >> n;

    for (int i=0;i<n;i++) {
        int c, nc; cin >> c >> nc;
        vector<int> cities;
        for (int j=0;j<nc;j++) {
            int x; cin >> x; cities.push_back(x);
        }
        // build graph 
        for (int ca=0;ca<cities.size();ca++) {
            for (int cb=ca+1;cb<cities.size();cb++) {
                adj[cities[ca]].push_back({cities[cb], cost(c, cb-ca)});
            }
        }
    }

    fill(dist, dist+MAXN, cost(oo, oo));
    set<pair<cost, int>> pqueue;
    
    pqueue.insert(make_pair(cost(0,0), a));
    dist[a] = {0,0};
    while (!pqueue.empty()) {
        auto [node_dist, node] = *pqueue.begin();
        pqueue.erase(pqueue.begin());
        for (auto [nei, nei_cost]: adj[node]){
            if ( add(node_dist, nei_cost) < dist[nei]) {
                dist[nei] = add(node_dist, nei_cost);
                pqueue.insert(make_pair(dist[nei], nei));
            }  
        }
    } 

    if (dist[b].first > 1e17) {
        dist[b] = {-1,-1};
    }
    cout << dist[b].first << " " << dist[b].second << "\n";

    return 0;
}