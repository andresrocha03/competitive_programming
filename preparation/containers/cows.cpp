#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //construct cow mapping to index and milk produced
    vector<string> cn = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> cmilk;

    //initialize map
    for (int i=0; i<7;i++) cmilk[cn[i]] =0;
    
    
    int n; cin >> n;
    int milk;
    string name;

    //read input
    for (int i=0;i<n;i++) {
        cin >> name >> milk;
        cmilk[name] += milk;
    }

    //put in a set to have order
    set<pair<int,string>> cs;
    for (auto cow:cmilk) {
        cs.insert(make_pair(cow.second, cow.first));
    }

    int f = 1e6; 
    int cand = -1;
    int tie  = 0 ;
    string candname;
    int i =0;
    for (auto cow:cs) {
        if (cow.first > cs.begin()->first && cand ==-1) {
            cand = cow.first;
            candname = cow.second;
        }
        else if (cand != -1 && cow.first == cand) {
            cout << "Tie\n";
            tie = 1;
            break;
        }
    }

    if (cand == -1) cout << "Tie\n";
    else if(tie == 0) cout << candname << "\n";

    return 0;
}