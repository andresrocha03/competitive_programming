#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
const int MAX2N = 2*MAXN + 2;


int cap[MAX2N][MAX2N];
int flow[MAX2N][MAX2N];
bool visited[MAX2N];

bool dfs(int s) {
    if (visited[s]) return false;
    if (s==MAX2N-1) return true;

    visited[s]=true;

    for (int i=0;i<MAX2N;i++) {
        if (flow[s][i] < cap[s][i]) {
            if (dfs(i)) {
                flow[s][i]++;
                flow[i][s]--;
                return true;
            }
        }
    }
    return false;
}

int main()  { 
    int N, K;
    cin >> N >> K;

    for (int i=0;i<MAXN;i++ ) {
        cap[MAX2N-2][i] =1;
    }

    for (int i=0;i<MAXN;i++ ) {
        cap[MAXN + i][MAX2N-1] =1;
    }

    int r, c;
    for (int i=0;i<K;i++) {
        cin >> r >> c;
        cap[r][c+MAXN] = 1;
    }

    //fordfulkerson
    int res =0;
    while(dfs(MAX2N-2)) {
        fill(visited, visited+MAX2N, false);
        res++;
    }

    cout << res;




    return 0;
}