#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll oo = 1e18;

int main() {

    ll n,m; cin >> n >> m;

    vector<ll> fs, ss;

    for (int i=0;i<n;i++) {
        int f, s; cin >> f >> s;
        fs.push_back(f);
        ss.push_back(s);
    }

    deque<int> nxt_s = {0};
    deque<int> cwe;
    ll currF =0; 
    ll currS = -oo; 
    ll bestS = oo; 
    for (int i=0;i<n;i++) {
        currF += fs[i];
        currS = max(currS, ss[i]);
        
        //queue of next s candidates
        if (ss[i] > ss[nxt_s.back()]) {
            while (!nxt_s.empty() && ss[i] > ss[nxt_s.back()]) {
                nxt_s.pop_back();
            }
        }
        nxt_s.push_back(i);

        // current elements in the window
        cwe.push_back(i);
        if (currF >= m) {
            bestS = min(currS, bestS);
            while (!cwe.empty() && currF >= m) {
                currF -= fs[cwe.front()];
                if (nxt_s.front() == cwe.front()) nxt_s.pop_front();
                cwe.pop_front();
            }
            currS = ss[nxt_s.front()];
        }
    }

    cout << bestS << "\n";

    return 0;
}