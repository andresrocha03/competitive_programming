#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;

    while (t--) {
        int n;cin>>n;
        vector<int> inputt;

        for (int i=0;i<n;i++) {
            int x; cin >> x;
            inputt.push_back(x);
        }

        int maxxfreq=0; 
        int maxximpar=0;
        int maxx4 = 0;
        int maxx2=0;
        unordered_map<int, int> freq;
        for (auto num:inputt) {
            freq[num]++;
            maxxfreq = max(maxxfreq, freq[num]);
            if (num%2!=0) maxximpar++;
            else if (num%4==0) maxx4++;
            else maxx2++;
        }

        int res = max(maxxfreq, max(maxximpar, max(maxx2, maxx4)));

        cout << res << "\n";
    }


    return 0;
}