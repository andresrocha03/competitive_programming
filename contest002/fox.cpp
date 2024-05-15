#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,borda=1,done=0;

    cin >>  n;
    cin >> m;

    for (int i=0; i<n; i++) {
        done =0;
        for (int j=0; j<m; j++) {
            if (i%2 == 0) {
                cout << "#";
                if (j == m-1) {
                    cout << "\n";
                }
            }
            else if (j == m-1 && borda ==1 && done ==0) {
                cout << "#" << "\n";
                borda =0;
            }
            else if (j == 0 && borda ==0) {
                cout << "#";
                borda = 1;
                done = 1;
            }
            else {
                cout << ".";
                if (j == m-1) {
                    cout << "\n";
                }
            }

        }
    }
        

}