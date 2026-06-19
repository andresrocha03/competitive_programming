#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
const int MAXNODES = MAXN   * MAXN;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

vector<string> grid; 
vector<pair<int, char>> adj[MAXNODES];
vector<char> out;
bool visited[MAXNODES];

int node(int i, int j) {
    return j + i*MAXN;
}

int find_path(int s, int e) {
    if (s == e) return true;

    if (visited[s]) return false;

    visited[s] = true;

    for (auto [v, label]: adj[s]) {
        if (find_path(v,e)) {
            out.push_back(label);
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nr, nc; cin >> nc >> nr;

    for (int i=0;i<nr;i++) {
        string line; cin >> line;
        grid.push_back(line);
    }

    int start, end;

    for (int i=0;i<nr;i++) {
        for (int j=0;j<nc;j++) {
            if (grid[i][j] == 'R') start = node(i,j);    
            else if (grid[i][j] == 'D') end = node(i, j);
            else if (grid[i][j] == '#') continue;
            for (int d = 0;d<4; d++ ) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (nx >= 0 && nx < nr && ny >=0 && ny < nc) {
                    if (grid[nx][ny] != '#') adj[node(i,j)].push_back({node(nx, ny), dir[d]}); 
                }

            }
        }
    }

    find_path(start, end);

    for (int i = (int)out.size() - 1; i >= 0; i--) cout << out[i];

    return 0;
}