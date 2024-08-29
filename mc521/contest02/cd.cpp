#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m, res=0;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        int x;
        set<int> jack;
        set<int> jill;
        for (int i=0; i<n; i++) {
            cin >> x; 
            jack.insert(x);
        }
        for (int i=0; i<m; i++) {
            cin >> x;
            jill.insert(x);
        }
        set<int> ans;
        set_intersection(jack.begin(),jack.end(),
                         jill.begin(), jill.end(),
                         inserter(ans, ans.begin()));
        cout << ans.size() << "\n";
        cin >> n >> m;
    }


}