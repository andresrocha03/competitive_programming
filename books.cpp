#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v;
    int back=0,day=1,n,q,kidl=-1,kidb=-1,number=0;

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> n;   
        for (int x=0; x<n; x++) {
            cin >> number;
            v.push_back(number);
        }
        for (int j=0; j<n; j++) {
            kidl = j + 1;
            //cout << "j" << j << " ";
            while (back != 1) {
                kidb = v[kidl-1];
                //cout << "borrow " << kidb ;
                if (kidb == j+1) {
                    back = 1;
                    cout << day << " "; 
                }
                else {
                    kidl = kidb;
                    day++;
                }
            }
            back = 0;
            kidl = -1;
            kidb = -1;
            day  = 1;
        };
        cout << "\n";
        v.clear();
    }
    




}