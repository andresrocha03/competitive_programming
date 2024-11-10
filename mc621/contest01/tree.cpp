#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    //compute distances
    vector<int> dist;
    for (int i = 0; i < n-1; i++) {
        dist.push_back(v[i+1] - v[i]);
    }

    //search multiples
    int j = 0;
    int max = dist[0];
    for (int i = 1; i < n; i++) {
       max = gcd(max, dist[i]);
    }
    // cout << max << "\n";

    //print result
    cout << ((v[n-1] - v[0])/max) - v.size() + 1<< "\n";

    return 0;
}