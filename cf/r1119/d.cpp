#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;

    while (t--) {
        int n;cin>>n;
        vector<int> nums;

        int zeros=0;
        for (int i=0;i<n;i++) {
            int x;cin >> x;
            if (!x) zeros++;
            nums.push_back(x);
        }

        if (!zeros) {
            cout << "yes\n";
            for (int i=0;i<n;i++) {
                cout << "a";
            }
            cout << "\n";
        }
        else if (zeros==1) {
            cout << "no\n";
        }
        else if (zeros>1) {
            cout << "yes\n";
            bool a=false;
            for (int i=0;i<n;i++) {
                if (!nums[i] && !a) {
                    cout << "a";
                    a = true;
                }
                else if (!nums[i]) cout << "b";
                else cout << "c";
            }
            cout << "\n";
        }

    }


    return 0;
}