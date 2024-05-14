#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x,answer=1,len=1;
    vector<int> v;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x; 
        v.push_back(x);
    }

    for (int i=0;i<n-1;i++) {
        if (v[i+1] >= v[i]) {
            len++;
        } 
        else {
            len=1;
        }
          if (len > answer) {
            answer =len;
        }
    }
    cout << answer;
}