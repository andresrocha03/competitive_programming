#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;

ll MOD = 1000000007;

struct Matrix {
    int m;
    std::vector<std::vector<ll>> mat;

    // Constructor
    Matrix(int size) : m(size), mat(size, std::vector<ll>(size)) {}

};


Matrix matMul(Matrix& a, Matrix& b, int size) {
    Matrix ans(size);
    ll i, j, k;
    
    // Perform matrix multiplication
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            for (k = 0; k < size; k++) {
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                ans.mat[i][j] %= MOD;
            }
        }
    }
    
    return ans;
}

Matrix matPow(Matrix base, unsigned long long n, int size) {
    Matrix ans(size);
    ll i, j;
    
    // Initialize the answer as the identity matrix
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            ans.mat[i][j] = (i == j);
        }
    }
    
    // Perform matrix exponentiation
    while (n > 0) {
        if (n % 2 == 1) {
            ans = matMul(ans, base, size);
        }
        base = matMul(base, base, size);
        n /= 2;
    }
    
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,n,m, a,b;


    cin >> n >> m >> k;
    
    Matrix res(n);
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        res.mat[a-1][b-1]+=1;
    }

    res = matPow(res,k, n);
    int num = res.mat[0][n-1];
    cout << num;
}