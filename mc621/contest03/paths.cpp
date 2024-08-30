#include <bits/stdc++.h>
using namespace std;
#define MAX 101 
typedef long long ll ;

ll MOD = 1000000007;

ll in[MAX][MAX];
ll ans[MAX][MAX];
ll prod[MAX][MAX];

//o codigo abaixo foi retirado dos slides da aula e adaptado ao problema
void matMuli(ll a[MAX][MAX], ll b[MAX][MAX], ll size) {
    ll i, j, k;
    // Perform matrix multiplication
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            prod[i][j] = 0;
            for (k = 0; k < size; k++) {
                prod[i][j] += a[i][k] * b[k][j];
                prod[i][j] = prod[i][j]%MOD;
            }
        }
    }
}

void matPow(unsigned long long n, ll size) {
    ll i, j;
    
    // Initialize the answer as the identity matrix
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            ans[i][j] = (i == j);
        }
    }
    
    // Perform matrix exponentiation
    while (n > 0) {
        if (n % 2 == 1) {
            // int res[MAX][MAX];
            matMuli(ans, in, size);
            for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                    ans[i][j] = prod[i][j];
                }
            }
        }
        matMuli(in, in, size);
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                in[i][j] = prod[i][j];
            }
        }
        n /= 2;
    }
    
}
//o codigo acima foi retirado dos slides da aula e adaptado ao problema

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,n,m, a,b;


    cin >> n >> m >> k;
    
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        in[a-1][b-1]+=1;
    }

    matPow(k, n);
    ll num = ans[0][n-1];
    cout << num;
}