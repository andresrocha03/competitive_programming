#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        vector<int> nums(n);
        for (int i=0;i<n;i++) {
            cin >> nums[i];
        }

        //compute range of restricted positions
        vector<int> diff(n+1);
        for (int i=0;i<n;i++) {
            if (nums[i] >0 ) {
                diff[max(0,i-nums[i]+1)]++;
                diff[min(n,i+nums[i])]--;
            }
        }

        vector<bool> restricted(n);
        int sum=0;
        for (int i=0;i<n;i++) {
            sum += diff[i];
            restricted[i] = (sum>0);
        }

        bool possible = true;
        for (int i=0;i<n && possible;i++) {
            if (nums[i] >= 0 && (i - nums[i] < 0 || restricted[i-nums[i]]) && (i + nums[i] >= n || restricted[i+nums[i]])) possible = false;
        }

        if (possible) {
            for (int i=0;i<n;i++) {
                cout << (!restricted[i]);
            }
            cout << "\n";
        }
        else {
            cout << "-1\n";
        }

    }


    return 0;
}