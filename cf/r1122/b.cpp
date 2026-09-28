#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;cin >> t;

    while (t--) {
        vector<long long> vec(3);
        for (int i=0;i<3;i++) {
            cin >> vec[i];
        }

        if (vec[0] >= vec[1]) {
            cout << (vec[0]+vec[2]) - vec[1] << "\n";
        }
        else {
            if (vec[2] > 2*(vec[1]-vec[0]))
                cout << (vec[0]+vec[2]) - vec[1] << "\n";
            else 
                cout << (vec[1]-vec[0]) << "\n";
        }

    }


    return 0;
}