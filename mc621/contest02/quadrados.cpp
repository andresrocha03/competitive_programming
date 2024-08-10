#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

char s[MAX], res[MAX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    char dchar;
    int dint, carry=0;
    cin >> m;
    cin >> s;
    strcpy(res,s);
    
    for (int i=m-1; i>=0; i--) {
        dchar = s[i];
        dint = dchar - '0';
        
        if (dint <= 4) {
            dint = 2*dint + carry;
            carry = 0;    
        }
        else {
            dint = ((2*dint) % 10) + carry;
            carry = 1;
        }
        dchar = dint + '0';
        res[i] = dchar;
    }

    if (carry) {
        cout << '1';
    }

    dchar = res[m-1];
    dint = dchar - '0';
    dint++;
    dchar = dint + '0';
    res[m-1] = dchar;

    cout << res << "\n";
    return 0;
}