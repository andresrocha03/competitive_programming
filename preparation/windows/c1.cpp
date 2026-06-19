#include <bits/stdc++.h>
using namespace std;

int freq[256];
int nb=0;

void change(int a, int c) {
    if (freq[a]==0) nb++;
    freq[a]+=c;
    if (freq[a]==0) nb--;
}



int main() {
    int f, s; cin >> f >> s;
    string ref, coded;
    cin >> ref >> coded;
    int res=0;
    for (int i=0;i<f;i++) {
        change((unsigned int)ref[i], -1);
        change((unsigned int)coded[i], +1);
    }

    for (int i=f;i<=s;i++) {
        if (nb==0) res++;
        change((unsigned int)coded[i-f], -1);
        change((unsigned int)coded[i], +1);     
    }

    cout << res << "\n";
    return 0;
}