#include <bits/stdc++.h>
using namespace std;

int main() {
    char date[10];
    int maxt = -51;
    int mint = 51;
    int t;
    char s;
    
    while (scanf("%s%c",date, &s) != EOF) {
        cout << string(date) << "\n";
        while (s != '\n' ) {
            int r = scanf("%d%c",&t, &s);
            if (r !=2) break;
            // cout << t << '\n';
            maxt = max(t, maxt);
            mint = min(t, mint);
        }
    }
    cout << mint << maxt << "\n";

    return 0;
}