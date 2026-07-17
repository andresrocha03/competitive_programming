//Problem: Given an array of numbers (bananas piles) and a integer h, find out minimum rate in which I can consume piles, respecting the time limit h
//Sol: Use binary search to find the minimum true value of the function that tells if a rate is valid or not

#include <bits/stdc++.h>
using namespace std;

bool ok(long long h, int brate, vector<int>& piles) {
    long long time = 0; 
    for (int i=0;i<piles.size();i++) {
        time += (piles[i]/brate) + min(1, piles[i]%brate);
    }
    if (time <= h) return true;
    else return false;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int z = *max_element(piles.begin(), piles.end());
    int x = 0;
    for (int b=z;b>=1;b/=2) {
        while (!ok(h, x+b, piles)) x += b;
    }
    return x+1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> piles;
    
    for (int i=0; i<n;i++) {    
        int x; cin >> x;
        piles.push_back(x);
    }

    int h; cin >> h;

    int x = minEatingSpeed(piles, h);
    cout << x;

}
