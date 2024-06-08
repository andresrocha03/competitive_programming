#include <bits/stdc++.h>
using namespace std;


typedef pair<int, double> ii;
typedef pair< double,int> ie;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

vi taken;  // global boolean flag to avoid cycle
priority_queue<ie> pq; // priority queue to help choose shorter edges

void process(int vtx, const AdjList  &AdjList) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) {
            pq.push(ie(-v.second, -v.first)); // sort by (inc) weight then by (inc) id
        }
    }
}

double dist(pair<double, double> point1, pair<double, double> point2) {
    double x1 = point1.first;
    double y1 = point1.second;
    double x2 = point2.first;
    double y2 = point2.second;

    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,V; // number of vertices
    double x, y;

    cin >> t;
    while (t--) {
        cin >> V;
        AdjList AdjList (V);
        pq = priority_queue<ie>();
        vector<pair<double,double>> islands;
      
        for (int i=0;i<V;i++){
            cin >> x >> y;
            islands.push_back(make_pair(x,y));
        }

        for (int i=0; i<islands.size(); i++) {
            for (int j=0; j<AdjList.size(); j++) {
                if ( j != i) {
                    double wei = dist(islands[i], islands[j]);
                    AdjList[j].push_back(make_pair(i, wei));
                }
            }
        }
        
        // Assume the graph is stored in AdjList, pq is empty
        taken.assign(V, 0); // no vertex is taken at the beginning
        process(0, AdjList); // take vertex 0 and process all edges incident to vertex 0

        double mst_cost = 0;
        while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
            ie front = pq.top(); pq.pop();
            int u = -front.second; 
            double w = -front.first; // negate the id and weight again
            if (!taken[u]) { // we have not connected this vertex yet
                mst_cost += w;
                // cout << w << "\n";
                process(u, AdjList); // take u, process all edges incident to u
            }
            // each edge is in pq only once!
        }
        cout << fixed << setprecision(3) << mst_cost << "\n";
    }
    return 0;
}