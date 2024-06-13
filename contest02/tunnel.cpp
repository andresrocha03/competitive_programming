#include <bits/stdc++.h>
using namespace std;


int carin[100001];
int carout[100001];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> carin[i];
    }    
    int j = 0;
    set<int> fined;
    for (int i=0;i<n;i++) {
        cin >> carout[i];
        // cout << "carout " <<carout[i] << "\n";
        // cout << "carin " <<carin[j] << "\n";
        if (carout[i] != carin[j]) {
            
            fined.insert(carout[i]);
        }
        else {
            j++;
            if (fined.find(carin[j]) != fined.end()) {
                j++;
            }
        }
    }  

    cout << fined.size() << "\n";

}
