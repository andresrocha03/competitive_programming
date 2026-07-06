#include <bits/stdc++.h>
using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,s; cin >> n >> s;

    vector<int> id, vs;

    id.push_back(0);
    vs.push_back(0);
    for  (int i=0;i<n;i++) {
        int q, v; cin >> q >> v;
        id.push_back(q);
        vs.push_back(v);
    }

    int pos = s;
    int pow = 1;
    int res=0;
    int w = 1;
    const int MAXN = 1e5+1;
    set<pair<int,pair<int, int>>> visited;
    bool broken[MAXN];
    fill(broken, broken+MAXN, false);

    while (pos >=1 && pos<=n){
        pair<int, pair<int,int>> state = {pos, {pow, w}};
        if (visited.find(state) != visited.end()) {
            break;
        }
        visited.insert({pos, {pow, w}});

        // check if it is jump pad or target
        // cout << "pos: " << pos << " pow: " << pow << " w: " << w << "vs: " << vs[pos] <<  "\n";
        if (id[pos]) {
            //breakable
            if (vs[pos] <= pow && !broken[pos]) {
                //break!
                // cout << "visited " << visited[pos] << "\n";
                broken[pos] = true;
                res++;
            }
        }       
        else {
            //jump pad - toin oin oin oin oin
            w *= -1;
            pow = pow + vs[pos];
        }
       
        pos = pos + w*pow;
    }

    cout  << res << "\n";
    return 0;
}