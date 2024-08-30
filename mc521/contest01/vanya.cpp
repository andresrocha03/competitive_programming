#include <bits/stdc++.h>

using namespace std;


#define min -2000000000

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k,i;
    double x;
    vector<double> v;
   
    cin >> n >> k;
    i=0;
    while (i <n) {
        cin >> x;
        v.push_back(x);
        i++;
    }     

    sort(v.begin(),v.end());

    double diff = min;
    for (int j=0; j<n-1; j++) {
        if (v[j+1] - v[j] > diff) {
            diff = double(v[j+1]) - double(v[j]);
        }
    }
    double leftdist;
    double rightdist;

    leftdist = v[0] - 0;

    rightdist = k - v[n-1];
    

    // cout << v[n-1] << "\n";
    // cout << k << "\n";
    // cout << leftdist << "\n";
    // cout << rightdist << "\n";

    cout << setprecision(10);
    if (leftdist > diff/2.0 || rightdist > diff/2.0) {
        if (leftdist > rightdist) cout << leftdist;
        else cout << rightdist;
    }
    else cout << diff/2;
}