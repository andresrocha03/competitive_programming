#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
const int MAXN2 = 2 * MAXN + 2;

int cap[MAXN2][MAXN2];
int flow[MAXN2][MAXN2];
int N, K;

bool visited[MAXN2];

bool dfs(int s) {
    if (visited[s]) return false;
    if (s == MAXN2 -1) return true;

    visited[s] = true;

    for (int j=0;j<MAXN2;j++) {
        if (flow[s][j] < cap[s][j]) {
            if (dfs(j)) {
                flow[s][j]++;
                flow[j][s]--;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    cin >> N >> K;
    // source to rows nodes
    for (int i = 0; i < MAXN; i++) {
        cap[MAXN2 - 2][i] = 1;
    }
    // columns to target node
    for (int i = 0; i < MAXN; i++)  {
        cap[i + MAXN][MAXN2 - 1] = 1;
    }

    int r, c;
    for (int i = 0; i < K; i++){
        cin >> r >> c;
        cap[r][c + MAXN] = 1;
    }

    // FordFulkerson
    int res = 0;
    while (dfs(MAXN2 - 2)) {
        fill(visited, visited + MAXN2, false);
        res++;
    }
    cout << res;

    return 0;
}