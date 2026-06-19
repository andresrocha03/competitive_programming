#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;

int N;
int x[MAXN];
int y[MAXN];
int p[MAXN];
int cnt=0;
bool visited[MAXN];

int sq(int a) {return a*a;}

void dfs(int s) {
    if (visited[s]) return;
    
    visited[s] = true;
    cnt++;

    for (int i=0;i<N;i++){
        int dist2 = sq(x[i] - x[s]) + sq(y[i]-y[s]);
        int reach = sq(p[s]);
        if (dist2 <= reach) dfs(i);    
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i=0; i<N;i++) {
        cin >> x[i] >> y[i] >> p[i];
    }
    
    int res = 0;
    for (int i=0; i<N;i++) {
        fill(visited, visited + N, false);
        cnt = 0;
        dfs(i);
        res = max(cnt, res);
    }
    
    cout << res << "\n";
    return 0;
}