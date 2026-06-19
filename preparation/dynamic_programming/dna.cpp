#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 500 + 1;
const ll INF = 1e18;
int N;

ll dp[MAXN][MAXN];
vector<ll> dna;
vector<ll>totsum;

ll cost(int i, int j) {
    if (i+1 == j) {
        return 0;
    }
    
    ll & cur = dp[i][j];

    
    if (cur == INF) {
        for (int k=i+1;k<j;k++) {
            cur = min(cost(i, k) + cost(k, j) + (totsum[j-1] - totsum[i-1]), cur) ;
        }
    }
    return cur;
}


int main() {
    cin >> N;

    ll l;
    dna.push_back(0);
    for (int i=0;i<N;i++) {
        cin >> l;
        dna.push_back(l); 
    }


    int i = 1; 
    int j = N+1;
    ll tot   = 0 ;
    totsum.assign(N+1, 0);
    for (int i=1;i<N+1;i++) {
        tot += dna[i];
        totsum[i] = tot;
    }
    
    for (int i=0;i<MAXN;i++) {
        fill(dp[i], dp[i] + MAXN, INF);
    }

    ll res = cost(i,j);
    cout << res;

    return 0;
}