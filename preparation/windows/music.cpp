#include <bits/stdc++.h>
using namespace std;


int n,c;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // read input
    cin >> n;
    vector<int> notes;
    for (int i=0;i<n;i++) {
        int note; cin >> note;
        notes.push_back(note);
    }

    cin >> c;
    vector<int> rchord;
    for (int i=0;i<c;i++) {
        int note; cin >> note;
        rchord.push_back(note);
    }
    sort(rchord.begin(), rchord.end());

    vector<int> res;
    for (int i=0;i<n;i++) {
        vector<int> cand;
        for (int j=i; j-i+1<=c;j++) {
            //cout << j << " \n";
            cand.push_back(notes[j]);
        }
        sort(cand.begin(), cand.end());
        
        int diff = cand[0] - rchord[0];
        bool match=true;
        for (int j=1; j<c;j++) {
            if (diff != cand[j]-rchord[j]) {
                match=false;
                break;
            }
        }
        if (match) {
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for (int i=0;i<(int)res.size();i++) {
        cout << res[i] + 1<< "\n";
    }


    return 0;
}