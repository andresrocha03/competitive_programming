#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,res=0;
    string s;

    cin >> n >> s;

    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (j+i <= n) 
             {
                if (s[j-1] != s[j+i-1]) res = j; 
                else break;
            //     cout << s[j-1] << "\n";
            //     cout << s[j+i-1] << "\n";
              }
        }    
        cout << res << "\n";
        res = 0;
    }


    return 0;

}