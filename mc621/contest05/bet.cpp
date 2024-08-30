#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int dp[MAX][6*MAX+1];


int func(int k, int soma, int x) {
    if(dp[k][soma] != -1)
        return dp[k][soma];

    if (!k) {
        if (soma<x) {
            dp[k][soma] = 0;
            return 0;
        }
        else {
            dp[k][soma] =1;
            return 1;
        }
    }
    else {
        dp[k][soma] = 0;
        for (int i=1; i<7; i++) {
            dp[k][soma] += func(k-1, soma+i, x);
        }
    }
    return dp[k][soma];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    
    cin >>n>>  a>> b;
    memset(dp, -1, sizeof(dp));

    cout << func(n,0,a);
    cout << "\n";
    memset(dp, -1, sizeof(dp));
    cout << func(n,0,b+1);
    
    cout << "\n";


}