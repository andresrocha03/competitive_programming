#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin >> t;

    while (t--) {
        int n;cin >> n;
        vector<int> vec(3);
        for (int i=0;i<3;i++) {
            cin >> vec[i];
        }

        int mini = 10;
        for (auto x:vec) {
            mini = min(mini,x);
        }

        cout << (n-mini) << "\n";
    }

}