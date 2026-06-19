#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXN = 500+2;
const ll INF = 1e18;

int n;
ll dna[MAXN];
ll dp[MAXN][MAXN];
vector<ll> totsum;

ll cost(int i, int j) {
    if (i+1==j) return 0;

    ll& curr = dp[i][j];
    if (curr == INF) {
        for (int k=i+1;k<j;k++) {
            curr = min(curr, cost(i,k) + cost(k,j) + totsum[j-1] - totsum[i-1]);
        }
    }

    return curr;


}


int main () {

    cin >> n;
    
    for (int i=1;i<=n;i++) {
        cin >> dna[i];
    }

    totsum.assign(n+1, 0);
    for (int i=1;i<=n;i++) {
        totsum[i] = totsum[i-1] + dna[i];
    }

    for (int i=0;i<MAXN;i++) {
        fill(dp[i], dp[i] + MAXN, INF);
    }


    ll res = cost(1, n+1);

    cout << res;

    return 0;
}