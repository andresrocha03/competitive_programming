#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string str; cin >> str;
    set<string> seen;
    int found = 1;

    for (int k=1; k<=n; k++) {
        found = 1;
        for (int i=0; i+k <= n; i++) {
            string sub = str.substr(i,k);

            if (seen.count(sub)) {
                found = 0; 
                break;
            }
            seen.insert(sub);
        }

        if (found) {
            cout << k << "\n";
            break;
        }
    }


    return 0;
}