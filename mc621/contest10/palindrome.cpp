#include <bits/stdc++.h>
using namespace std;

string s;
int l, r;
int dp[1001][1001];

int solve(int l,int r) {
    if (dp[l][r]==-1) {
        if (l>r) {
           return 0;
        }
        else if (l==r) return 1;
        else if (s[l]==s[r]) {
            dp[l][r] = 2 + solve(l+1, r-1);
            // cout << "l: " << l << "r: " << r << "\n";
            // cout << dp[l][r] << "\n";
        }
        else if (s[l] != s[r]) {
            dp[l][r] = max(solve(l, r-1), solve(l+1, r));
            // cout << "l: " << l << "r: " << r << "\n";
            // cout << dp[l][r] << "\n";
        }
    }
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.get();
    while (t--) {
        getline(cin, s);
        // cout << s << "\n";
        if (s != "") {
            memset(dp, -1, sizeof(dp));
            l = 0;
            r = int(s.size()) - 1;
            cout << solve(l,r) << "\n";
        }
        else cout << 0 << "\n";
        
    }


}