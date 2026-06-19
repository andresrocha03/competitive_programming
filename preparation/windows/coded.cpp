#include <bits/stdc++.h>
using namespace std;


int freq[256];
int nbm = 0;

void up(int pos, int d) {
    if (freq[pos] == 0) nbm++;
    freq[pos]+=d;
    if (freq[pos]==0) nbm--; 
}


int main() {
    
    int s, t; cin >> s >> t;
    int mm=0, res=0;

    string secret, txt;
    cin >> secret >> txt;

    for (int i=0;i<s;i++) {
        up(secret[i], -1);
        up(txt[i], +1);
    }

    for (int i=s;i<=t;i++) {
        if (nbm == 0) res ++;
        up(txt[i-s], -1);
        up(txt[i], +1);
    }

      

    cout << res << "\n";


}