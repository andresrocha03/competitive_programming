//problem: given a square matrix, rotate it 90 degrees clockwise in place.
//solution: rotate the matrix layer by layer, starting from the outermost and moving towards the center
//easier: transpose the matrix and then reverse each row

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0;j<n; j++) {
            cin >> mat[i][j];
        }
    }


    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n-1-i; j++) {

            int temp = mat[i][j];

            mat[i][j] = mat[n-1-j][i];
            mat[n-1-j][i] = mat[n-1-i][n-1-j];
            mat[n-1-i][n-1-j] = mat[j][n-1-i];
            mat[j][n-1-i] = temp;
        }
    }

    //alternative solution: transpose the matrix and then reverse each row
    // for (int i = 0; i < n; i++) {
    //     for (int j = i+1; j < n; j++) {
    //         swap(mat[i][j], mat[j][i]);
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     reverse(mat[i].begin(), mat[i].end());
    // } 

    cout << "[";
    for (int i=0; i<n; i++) {
        cout << "[";
        for (int j=0;j<n; j++) {
            cout << mat[i][j];
            if (j==n-1) cout << "]";
            else cout << ',';
        }
    }
    cout << "]";
}