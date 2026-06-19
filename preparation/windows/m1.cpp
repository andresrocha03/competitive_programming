#include <bits/stdc++.h>
using namespace std; 


int main () {
    int n; cin >> n;

    vector<int> notes;
    for (int i=0;i<n;i++) {
        int note; cin >> note;
        notes.push_back(note);
    }

    int c; cin >> c;
    vector<int> rc;
    for (int i=0;i<c;i++) {
        int nt; cin >> nt;
        rc.push_back(nt);
    }
    sort(rc.begin(),rc.end());

    vector<int> res;
    for (int i=0;i<n;i++) {
        vector<int> cand;
        for (int j=i;j-i+1<=c;j++) {
            cand.push_back(notes[j]);
        }
        sort(cand.begin(), cand.end());
        
        int diff = cand[0] - rc[0];
        bool match = true;
        for (int j=1;j<c;j++) {
            if ((cand[j] - rc[j]) != diff) {
                match = false;
                break;
            }
        }

        if (match) {
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for (auto idx:res) cout << idx + 1 << "\n";
    return 0;
}