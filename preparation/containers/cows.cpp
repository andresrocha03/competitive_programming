#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //construct cow mapping to index and milk produced
    vector<string> cn = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<int, string> cmilk;

    int n; cin >> n;
    int milk;
    string name;
    //read input

    for (int i=0;i<n;i++) {
        cin >> name >> milk;
        cmilk[milk] = name;
    }

    auto it = cmilk.lower_bound(0);

    auto it = cmilk.upper_bound(it->first);






    return 0;
}