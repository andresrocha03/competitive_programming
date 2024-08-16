#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;

ll MOD = 1000000007;


struct Matrix {
    int m;
    std::vector<std::vector<int>> mat;

    // Constructor
    Matrix(int size) : m(size), mat(size, std::vector<int>(size)) {}

    // Function to display the matrix (for testing purposes)
    void display() const {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};


Matrix matMul(Matrix a, Matrix b, int size) {
    Matrix ans(size);
    ll i, j, k;
    
    // Initialize the answer matrix
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            ans.mat[i][j] = 0;
        }
    }
    
    // Perform matrix multiplication
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            for (k = 0; k < size; k++) {
                ans.mat[i][j] += (a.mat[i][k] % MOD) * 1LL*(b.mat[k][j] % MOD)%MOD;
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
    int t,n,m;


    cin >> t;
    
    while (t--){
        cin >> m >> n;
        Matrix res(m);
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                cin >> res.mat[i][j];
            }
        }
        Matrix res2(m);
        res2 = matPow(res,n, m);
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                cout << res2.mat[i][j];
                if (j<m-1) cout << " ";
            }
            cout << "\n";
        }
    }
}