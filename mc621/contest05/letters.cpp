#include <bits/stdc++.h>
using namespace std;
#define MAX 300

char que[5][3] = {{{'#'},{'#'},{'#'}},{{'#'},{'.'},{'#'}},{{'#'},{'#'},{'#'}},{{'.'},{'.'},{'#'}},{{'.'},{'.'},{'#'}}};
char efe[5][3] = {{{'#'},{'#'},{'#'}},{{'#'},{'.'},{'.'}},{{'#'},{'#'},{'.'}},{{'#'},{'.'},{'.'}},{{'#'},{'.'},{'.'}}};
char input[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >>n >> m;
    char c;
    int isefe, isque, nf=0,nq=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> c;
            input[i][j] = c;
        }
    }
            
    for (int i=0;i<=m-3;i++) {  
        for (int p=0; p<=n-5;p++) {
            isefe=1;
            isque=1;
            int r =0;  
            for (int j=p;j<p+5;j++) {
                int l = 0;
                for (int k=p;k<p+3;k++) {
                    if ((input[j][k] != efe[r][l]) && (efe[r][l]== '#')) { isefe=0;}
                    if (input[j][k] != que[r][l] && (que[r][l] == '#')) {isque=0;}
                    if ((!isefe)&&(!isque)) break;
                    l++;
                }
                r++;
            }
            if (isefe) nf++;
            if (isque) nq++;
        }
    }

    cout << nq << "\n";
    cout << nf << "\n";
}