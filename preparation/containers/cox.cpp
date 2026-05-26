#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    map<string, int> c2m;
    string name;
    int milk;
    vector<string> names = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie","Henrietta"};
    for (int i=0;i<n;i++) {
        cin >> name;
        cin >> milk;
        c2m[name] += milk;
    }
    map<int, vector<string>> cpm;
    for (auto nam:names) {
        cpm[c2m[nam]].push_back(nam);
    }
    auto least2 = next(cpm.begin());

    if (least2 == cpm.end() || least2->second.size() != 1) {
        cout << "Tie\n";
    }
    else cout << least2->second[0] << "\n";


    return 0;
}