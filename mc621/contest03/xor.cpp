#include <bits/stdc++.h>
using namespace std;
#define MAX_N 2

typedef long long ll ;

ll MOD = 1000000007;



struct Matrix { 
    ll mat[MAX_N][MAX_N]; 
    };

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans;
    ll i, j, k;
    
    // Initialize the answer matrix
    for (i = 0; i < MAX_N; i++) {
        for (j = 0; j < MAX_N; j++) {
            ans.mat[i][j] = 0;
        }
    }
    
    // Perform matrix multiplication
    for (i = 0; i < MAX_N; i++) {
        for (j = 0; j < MAX_N; j++) {
            for (k = 0; k < MAX_N; k++) {
                ans.mat[i][j] = ans.mat[i][j]^((a.mat[i][k] % MOD) * (b.mat[k][j] % MOD));
                ans.mat[i][j] %= MOD;
            }
        }
    }
    
    return ans;
}

Matrix matPow(Matrix base, unsigned long long n) {
    Matrix ans;
    ll i, j;
    
    // Initialize the answer as the identity matrix
    for (i = 0; i < MAX_N; i++) {
        for (j = 0; j < MAX_N; j++) {
            ans.mat[i][j] = (i == j);
        }
    }
    
    // Perform matrix exponentiation
    while (n > 0) {
        if (n % 2 == 1) {
            ans = matMul(ans, base);
        }
        base = matMul(base, base);
        n /= 2;
    }
    
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, a, b, n;

    Matrix res;
    res.mat[0][0] = 1;
    res.mat[1][0] = 1;
    res.mat[0][1] = 1;
    res.mat[1][1] = 0;

    cin >> t;
     
    while (t--) {
        cin >> a >> b >> n;
        // int num=0;
        // Matrix res2;
        // res2 = matPow(res,n-1);
        // num = (a * res2.mat[0][0]) ^ (b * res2.mat[0][1]);
        // cout << num << "\n";
        vector<int> answer;
        answer.push_back(a);
        answer.push_back(b);
        answer.push_back(a^b);

        int carry = n%3;

        cout << answer[carry] << "\n";

    }


   


   


}