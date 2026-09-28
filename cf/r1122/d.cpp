#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        set<int> nums;
        for (int i=0;i<n;i++) {
            int x; cin >>x;
            nums.insert(x-i);
        }
        int last = 1e-9;
        int res= 0;
        int cur =0;
        for (auto x:nums) {
            if (x != last+1) {
                res = max(res, cur);
                cur = 0;
            }
            cur++;
            last = x;
        }
        res = max(res, cur);
        cout << res << "\n";
    }


    return 0;
}