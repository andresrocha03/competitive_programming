#include <bits/stdc++.h>
using namespace std;

const int  MAXN = 10000;
const int MAXK = 1000;

int A[MAXN+1];
int dp[MAXN +1];

int main() {

    int N,K;
    cin >> N >> K;

    for (int i=0;i<N;i++) {
        cin >> A[i];
    }

    dp[0] = A[0];
    for (int i=0;i<N;i++) {
        int mx = A[i];
        for (int j=i;  j >=0 && i-j+1<=K; j--) {
            
            mx = max(mx, A[j]);
            if (j==0) dp[i] = max(dp[i], mx*(i-j+1));
            else dp[i] = max(dp[i], dp[j-1] + mx*(i-j+1));
        }
    }

    int res = dp[N-1];
    cout << res;

    return 0;
}