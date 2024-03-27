#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> s;
    vector<int> v ={-1};
    int n,x,ultimo=-1,answer=0;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
        if (x != ultimo) {
            cout << x << "é diferente de " << ultimo << "\n";
            ultimo = x;
            if 
                answer++;
        }
    }
    cout << answer;
}