#include <bits/stdc++.h>
using namespace std;

long long dp[200][200];
string s;


long long strsum(int l, int r) {
    long long sum = 0;
    int exp = abs(l - r) + 1;
    for (int i=l; i<=r; i++) {
        sum += (s[i] - '0')*pow(10,exp);
        exp--;
    }
    return sum;
} 

long long solve(int l,int r) {
    if (l>=0)
        if (dp[l][r] == -1) {
            if (l>r) return 0;
            else if (l==r) return strsum(l,r);
            else if ((abs(l-r)+1)<10) return strsum(l,r);
            else {
                dp[l][r] = max(solve(l-1, r), solve(l, r+1));
            } 
        }
    }
    return dp[l][r];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        int l=0, r=int(s.size())-1;
        solve(l,r);
    }
    return 0;
}