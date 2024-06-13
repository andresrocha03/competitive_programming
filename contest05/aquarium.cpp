#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define MAX2 2000000004

int arr[MAX];
int check (long long ans, int n,int x) {
    long long water = 0;
    for (int i=0; i<n; i++) {
        if (ans > arr[i]) {
            water += ans - arr[i];
        }
    }
    if (water <= x) return 1; 
    else return 0;
}

void solve (int n, int x) {
    long long lo = 1, hi = MAX2, mid = 0, ans = 0;
    while (lo <= hi) {
        mid = (lo+hi)/2;
        if (check(mid, n, x)) { ans = mid; lo = mid+1;}
        else hi = mid-1;
    }
    cout << ans << "\n"; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i=0; i<n; i++) {
            cin >> arr[i]; 
        }
        solve(n,x);
    }
    return 0;
}