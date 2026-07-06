#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //read input
    ll n, t; cin >> n >> t;
    vector<pair<ll,ll>> cows;
    for (ll i=0;i<n;i++) {
        ll p,s; cin >> p >> s;
        cows.push_back(make_pair(p,s));
    }

    //calculate ideal final position of each cow
    vector<pair<ll,ll>> posif;
    for (ll i=0;i<n;i++) {
        ll posf = cows[i].second*t + cows[i].first;
        posif.push_back({cows[i].first, posf});
    }

    //sort
    sort(posif.begin(), posif.end());

    // groups
    ll res=0;
    ll lpos = 1e18 + 1e9 +5;
    for (ll i =posif.size()-1;i>=0;i--) {
        if (posif[i].second < lpos) {
            res++;
            lpos = posif[i].second;
        }
    }

    cout << res << "\n";


    return 0;
}