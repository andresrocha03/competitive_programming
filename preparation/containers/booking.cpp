#include <bits/stdc++.h>
using namespace std;


int main() {

    int N, M; 
    cin >> N >> M;

    set<pair<int, int>> rooms;

    for (int i=0; i<N; i++) {
        int c; cin >> c;
        rooms.insert(make_pair(c, i));
    }
    
    for (int i=0; i<M; i++) {
        int c; cin >> c;

        auto it = rooms.lower_bound({c,0});

        if (it == rooms.end()) cout << -1 << "\n";
        else {
            cout << it->second << "\n";
            rooms.erase(it); //set the roomn to occupied
        }
        
    }

    return 0;
}