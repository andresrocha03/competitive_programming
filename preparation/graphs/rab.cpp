#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
const int MAXNODES = MAXN * MAXN;

int start, dest;

vector<string> grid;
vector<pair<int, char>> adj[MAXNODES];
vector<char> out;
bool visited[MAXNODES];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char dir[4] = {'U','D','L','R'};

int node(int x, int y) {
    return y + x*MAXN;
}

bool find_path(int s, int d) {
    if (s == d) return true;

    if (visited[s]) return false;

    visited[s] = true;

    for (auto [v,label] : adj[s]) {
        if (find_path(v,d)) {
            out.push_back(label);        
            return true;
        }
    }

    return false;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nr, nc;

    cin >> nc >> nr;

    for (int i=0;i<nr;i++) {
        string line; cin >> line; grid.push_back(line);
    }

    for (int i=0;i<nr;i++) {
        for (int j=0;j<nc;j++) {
            char c = grid[i][j];
            if (c == 'R') start = node(i,j);
            else if (c == 'D') dest = node(i,j);
            else if (c == '#') continue;

            for (int d=0;d<4;d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx >=0 && nx < nr && ny >=0 && ny < nc) {
                    if (grid[nx][ny] != '#') adj[node(i,j)].push_back({node(nx, ny), dir[d]});
                }
            }
        }
    }

    find_path(start, dest);
    
    for (int i=(int)out.size()-1;i>=0;i--) cout << out[i];


    return 0;
}