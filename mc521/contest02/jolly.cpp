#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n, diff;
    bool jolly = true;
    vector<int> v;
    set<int> diffs;
    while (cin >> n) {
        for (int i=0; i<n; i++) {
            cin >> x;
            v.push_back(x);
        }
        for (int i=0; i<v.size()-1; i++) {
            diff = v[i] - v[i+1];
            diffs.insert(abs(diff));
        }
        jolly = true;
        for (int i = 1; i<n; i++) {
            if (diffs.find(i) == diffs.end()) {
                cout << "Not jolly" << "\n";
                jolly = false;
                break;
            }
        }
        if (jolly) cout << "Jolly" << "\n";
        v.clear();
        diffs.clear();
    }
    return 0;

}