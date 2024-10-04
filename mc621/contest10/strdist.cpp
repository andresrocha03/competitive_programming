#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


//o codigo abaixo foi retirado dos slides da aula
pair<int,int> match(string P, string Q, vector<vector<int>>& table) {
    // Needleman-Wunsch’s algorithm
    int n = static_cast<int>(P.size());
    int m = static_cast<int>(Q.size());
    
    // insert/delete = -1 point
    for (int i = 1; i <= n; i++) table[i][0] = i * -1;
    for (int j = 1; j <= m; j++) table[0][j] = j * -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // match = 2 points, mismatch = -1 point
            table[i][j] = table[i - 1][j - 1] + (P[i - 1] == Q[j - 1] ? 2 : -1);

            // gap = -1 point
            table[i][j] = max(table[i][j], table[i - 1][j] - 1); // delete character from P
            table[i][j] = max(table[i][j], table[i][j - 1] - 1); // delete character from Q
        }
    }

    // Print DP table
    cout << "DP table:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << setw(3) << table[i][j] << " ";
        }
        cout << endl;
    }

    // Print maximum alignment score
    cout << "Maximum Alignment Score: " << table[n][m] << endl;

    return make_pair(n,m);
}

void printop(vector<vector<int>>& table, pair<int,int> coord, string A, string B) {
    int steps =1;
    int j = 0, i =0;
    for (int k=0; k<coord.first-1; k--) {
        int r,d,diag;
        diag = table[i][j+1];
        d = table[i+1][j];
        r = table[i+1][j+1];
        if (r>d && r>diag) {
            cout << ++steps <<  "Replace " << i <<  "," << A[i-1];
            j++;
        }
        if (d>r && d>diag) {
            cout << ++steps <<  "Delete " << i <<  "," << A[i-1];
            i++;
        }
        if (diag>=r && diag>=d) {
            i++;
            j++;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string p, q;

    while (cin >> p) {
        cin >> q;
        vector<vector<int>> table(20);
        pair<int,int> coord = match(p,q, table);
        printop(table, coord, p, q);
    }


}