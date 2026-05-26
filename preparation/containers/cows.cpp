#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> names={"Bessie","Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> cows2milk;

    int n; cin >> n;

    for (int i=0;i<n;i++) {
        string name; cin >> name;
        int m; cin >>m;
        cows2milk[name] += m;
    }

    map<int,vector<string>> cowspermilk; 
    for (auto name:names) {
        cowspermilk[cows2milk[name]].push_back(name);
    }

    auto least2 = next(cowspermilk.begin()); 

    if (least2 == cowspermilk.end() || least2->second.size() != 1) cout << "Tie\n";
    else cout << least2->second[0] << "\n";


    return 0;
}