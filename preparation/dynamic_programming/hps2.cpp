#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int MAXN = 1e5+1;
const int MAXK = 20+1;

int moves[MAXN];
int dp[MAXN][MAXK][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;

    for (int i=1;i<=n;i++) {
        char m; cin >> m;
        if (m == 'H') moves[i] = 0;
        if (m == 'P') moves[i] = 1;
        if (m == 'S') moves[i] = 2;
    }

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=k;j++) {
            for (int s=0;s<3;s++) {
                if (i==0) dp[i][j][s] = 0;
                else if (j==0) {
                    int r =0;
                    if (s == moves[i]) r =1;
                    dp[i][j][s] = dp[i-1][j][s] + r;
                    
                }
                else {
                    int pm1 = (s+1)%3;
                    int pm2 = (s+2)%3;
                    int r =0;
                    if (s == moves[i]) r =1;
                    dp[i][j][s] = max(max(dp[i-1][j][s],dp[i-1][j-1][pm1]),dp[i-1][j-1][pm2]) + r; 
                }
            }
        }
    } 

     int res = max(max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]);
    cout <<res;




    return 0;
}