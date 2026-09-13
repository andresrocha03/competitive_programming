#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while (t--) {
        int n;cin>>n;

        int first = -1;
        int last = -1;
        bool done;
        vector<int> nums;
        for (int i=0;i<n;i++) {
            int x;cin>>x;
            nums.push_back(x);
        }

        for (int i=0;i<n;i++) {
            if (nums[i]) {
                first = i;
                if (nums[i]<0) nums[i]=1;
                break;
            }
        }

        for (int i=n-1;i>=0;i--) {
            if (nums[i]) {
                last = i;
                if (nums[i]<0) nums[i]=1;
                break;
            }
        }

        for (int i=0;i<n;i++) {
            if (nums[i]==1 || nums[i]==0) {
                cout << nums[i] << " ";
            }
            else cout << 0 << " ";
        }
        cout << "\n";
    }

    return 0;
}