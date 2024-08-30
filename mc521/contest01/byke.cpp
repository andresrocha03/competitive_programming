#include <bits/stdc++.h>
#define pb push_back 
using namespace std;

float agear[10005];
float bgear[10005];
vector<float> allgear(10005);

void solve() {
    float ratio; 
    int maximum = -1; 
    int lena, lenb; 
    int res = 0;
    lena = sizeof(agear)/sizeof(int);
    lenb = sizeof(bgear)/sizeof(int);

    // find maximum integer gear ratio
    for (int i=0; i<lena; i++) {
        for (int j = 0; j<lenb; j++) {
            ratio = bgear[j]/agear[i];
            if (floor(ratio) == ratio) {
                allgear.pb(ratio);
                if (int(ratio) > maximum) maximum = int(ratio);
            }
        }
    }    

    for (int i=0; i<allgear.size(); i++) {
        if (allgear[i] == maximum) res++;
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m,x;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x; 
        agear[i] = x;
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> x; 
        bgear[i] = x;
    }
    solve();

}