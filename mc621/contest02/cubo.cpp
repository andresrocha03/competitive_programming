#include <bits/stdc++.h>
using namespace std;
#define  MAX 1000000005

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, x, flag=1;
    vector<int> q1, q2;
    
    cin >> t;

    while (t--) {
        cin >> n >> m;
        flag=1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> x;
                q1.push_back(x);
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> x;
                q2.push_back(x);
            }
        }
        sort(q1.begin(),q1.end());
        sort(q2.begin(),q2.end());
        if (q1.size() == q2.size()) {
            for (int i=0; i<q1.size(); i++) {
                if (q1[i] != q2[i]) {
                    flag = 0; 
                    break;
                }
            }
        }
        if (flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        q1.clear();
        q2.clear();
    }
}