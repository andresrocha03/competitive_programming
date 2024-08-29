#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

vi taken;  // global boolean flag to avoid cycle
priority_queue<ii> pq; // priority queue to help choose shorter edges

void process(int vtx, const AdjList  &AdjList) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) {
            pq.push(ii(-v.second, -v.first)); // sort by (inc) weight then by (inc) id
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m=1,n=2,V,x,y,z,total=0; // number of vertices

    
    while (true) {
        cin >> m >> n;
        if (m==0) break;
        V = m;
        total = 0;
        AdjList AdjList (m);
        pq = priority_queue<ii>();
        
        for (int i=0; i<n; i++) {
            cin >> x >> y >> z; 
            AdjList[x].push_back(make_pair(y,z));
            AdjList[y].push_back(make_pair(x,z));
            total += z;
        }

        // Assume the graph is stored in AdjList, pq is empty
        taken.assign(V, 0); // no vertex is taken at the beginning
        process(0, AdjList); // take vertex 0 and process all edges incident to vertex 0

        int mst_cost = 0;
        while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
            ii front = pq.top(); pq.pop();
            int u = -front.second, w = -front.first; // negate the id and weight again
            if (!taken[u]) { // we have not connected this vertex yet
                mst_cost += w;
                process(u, AdjList); // take u, process all edges incident to u
            }
            // each edge is in pq only once!
        }
        cout << total - mst_cost << "\n";
        

    }
    return 0;
}