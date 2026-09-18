#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
 
    vector<int> v;
 
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
 
    set<int> numbers;
 
    for (int i =0; i<n; i++) {
        numbers.insert(v[i]);
    }
 
    int found = 0;
    for (int i =0; i<n; i++){
        if (numbers.find(x - v[i]) != numbers.end()) {
            int idx = (find(v.begin()+i+1, v.end(), x - v[i]) - v.begin());
            if (idx < n) {
                cout << i + 1 << " " << idx + 1 << "\n";
                found = 1;
                break;
            }
        }
    }
    if (!found) cout << "IMPOSSIBLE\n";
    
    // vector<int> s;
    // s.push_back(v[0]);
 
    // for (int i=1; i<n; i++) {
    //     s.push_back(s[i-1] + v[i]);
    // }
 
 
 
 
    return 0;
}