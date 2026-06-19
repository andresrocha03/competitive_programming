#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXK = 20;
int moves[MAXN+1];
int dp[MAXN+1][MAXK+1][3];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i=1;i<=N;i++) {
        char m; cin >> m;
        if (m == 'H') moves[i] = 0;
        if (m == 'P') moves[i] = 1;
        if (m == 'S') moves[i] = 2;
    }

    for (int i=0;i<=N;i++) {
        for (int j=0;j<=K;j++) {
            for (int s=0;s<3;s++) {
                if (i == 0) dp[i][j][s] = 0;
                else if (j==0) {
                    int r=0;
                    if (moves[i]==s) r = 1;
                    dp[i][j][s] = dp[i-1][j][s] + r;
                }
                else {
                    int pm1 = (s+1)%3;
                    int pm2 = (s+2)%3;
                    int r=0;
                    if (moves[i]==s) r = 1;
                    dp[i][j][s] = max(max(dp[i-1][j][s], dp[i-1][j-1][pm1]), dp[i-1][j-1][pm2]) + r;

                }
            
            }

        }
    }


    int res = max(max(dp[N][K][0], dp[N][K][1]), dp[N][K][2]);

    cout << res;

    return 0;
}