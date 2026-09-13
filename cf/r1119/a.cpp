#include <bits/stdc++.h>
using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string fields; cin >> fields;
        
        
        int field_idx = 1;
        set<char> fieldscheck;
        int res =0;
        for (auto c:fields) {
            fieldscheck.insert(c);

            if (field_idx%k==0) { //time to account for schools built in nhoj's fields
                if (!fieldscheck.count('0')) res++;
                fieldscheck.clear();
            }

            field_idx++;
        }

        cout << res << "\n";

    }


    return 0;
}