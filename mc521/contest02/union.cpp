#include <bits/stdc++.h>
#include <cstdio>

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

    int n,q,a,b;
    char op;
    cin >> n;
    UnionFind UF(n);
    cin >> q;
    for (int i=0;i<q;i++) {
        cin >> op;
        if (op == '?') {
            cin >> a;
            cin >> b;
            if (UF.isSameSet(a,b)) {
                printf("yes\n");
            } 
            else {
                printf("no\n");
            }
        }
        if (op == '=') {
            cin >> a;
            cin >> b;
            UF.unionSet(a,b);
        }

    }


    return 0;
}