#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;cin >> t;

    while (t--) {
        int n;cin >> n;
        string s;cin >> s;
        //count number of zeros
        int zer =0;
        for (auto c:s) zer += (c=='0');

        if (s[0]=='1') {
            cout << zer << "\n";
            continue;
        }

        int ones=0;
        int mini = 1e9;
        for (auto c:s) {
            ones += (c=='1');
            zer -= (c=='0');
            mini = min(mini, ones+zer);
        }
        cout << mini << "\n";

    }



    return 0;
}