#include <bits/stdc++.h>
using namespace std;


int carin[100002];
int carout[100002];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    cin >> n;
    for (int i=1;i<n+1;i++) {
        cin >> carin[i];
    }    
    
    for (int i=1;i<n+1;i++) {
        cin >> carout[i];
    }

    vector<int> orderout(n+1);
    for (int i=1;i<n+1;i++) {
        orderout[carout[i]] = i;
        // cout << carout[i] << " ";
    }
    // cout << "\n";
    
    vector<int> place(n+1);
    for (int i=1;i<n+1;i++) {
        place[i] = orderout[carin[i]];
        // cout << orderout[carin[i]] << " ";
    }
    // cout << "\n";

    int max = -10, ans = 0;
    for (int i=1;i<n+1;i++) {
        if (place[i] > max) {
            max = place[i];
        }
        else { 
            ans++;
        }
    }
    cout << ans << "\n";
}
