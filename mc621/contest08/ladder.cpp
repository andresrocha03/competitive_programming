#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    vector<int> index;
    vector<string> x;
    cin >> s >> t;
    int m=0;
    for (int i=0; i<s.size(); i++) {
        // cout << s[i] << t[i];
        if (s[i] != t[i]) {
            m++; 
            index.push_back(i); 
            // cout << index.size();
        }
    }
    int aux = m;
    int thereismenor =0;
    while (aux--) {
        // cout << "index size " << index.size() << "\n"; 
        for (int i=0; i<index.size(); i++) {
            if (t[index[i]] < s[index[i]]) {
                s[index[i]] = t[index[i]]; 
                index.erase(index.begin()+i);
                thereismenor=1;
                break;  
            }
        }
        if (!thereismenor) {
            for (int i=index.size()-1; i>=0; i--) {
                s[index[i]] = t[index[i]]; 
                index.erase(index.begin()+i);
                break;  
            }
        }
        x.push_back(s);
        thereismenor=0;
    }

    cout << m << "\n";
    for (int i=0; i<x.size(); i++) {
        cout << x[i] << "\n";    
    }
    return 0;
}