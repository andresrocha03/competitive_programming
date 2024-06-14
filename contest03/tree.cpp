#include <bits/stdc++.h>
#include <cstdio>
#define pb push_back
using namespace std;
typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
        p.assign(N, 0); for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else { p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++; }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        string edge; 
        string vertex;
        vector<string> edges;
       
        cin >> edge;
        while (edge[0] != '*') {
            edges.pb(edge);
            cin >> edge;
        }

        
        cin >> vertex;
        int sizeuf = 0, index=0;
        vector<int> pos(26);
        for (int i=0; i<vertex.size(); i++) {
            if (vertex[i] != ',') {
                pos[vertex[i]-65] = index;
                index++; 
                sizeuf++;
            }
        }
        
        UnionFind UF(sizeuf);
        for (int i=0;i<edges.size();i++) {
            int left = edges[i][1] - 65;
            int right = edges[i][3] - 65;
            UF.unionSet(pos[left],pos[right]);
            // cout << "disjointSets " <<  UF.numDisjointSets() << "\n";
        }
        int acorn=0, tree;
        for (int i=0;i<sizeuf; i++) {
            if (UF.sizeOfSet(i) == 1) {
                acorn++;
            }
        }
        tree =  UF.numDisjointSets() - acorn;
        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";

    }
    


    return 0;
}